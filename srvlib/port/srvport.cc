
#include "net/recvbuf.h"
#include "net/sendbuf.h"
#include "port/port.h"
#include "ar/ar.h"
#include "log/log.h"
#include "pblua/pblua.h"
#include "json/json.h"

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include <string.h>



#define NIL_TYPE  1
#define INT_TYPE  2
#define STR_TYPE  3
#define PROTOBUF_TYPE 4
#define JSON_TYPE  5
#define BSON_TYPE  6

#define POST_PROTO  1

#define MAX_ARG_COUNT 20

static void lua_printstack(lua_State *L) 
{
    lua_getglobal(L, "debug");  
    lua_getfield(L, -1, "traceback");  
    lua_pcall(L, 0, 1, 0);   
    const char* sz = lua_tostring(L, -1);  
    printf("%s\n", sz);
}

//login.hello_world
//hello_world
static int lua_pushluafunction(lua_State *L, const char *func)
{
    char *start = (char *)func;
    char *class_name = start;
    char *pfunc = start;
    while(*pfunc != 0)
    {
        if(*pfunc == '.' && class_name == start)
        {
            *pfunc = 0;
            lua_getglobal(L, class_name);
            *pfunc = '.';
            if(lua_isnil(L, -1)){
                return 0;
            }
            class_name = pfunc + 1;
        }else if(*pfunc == '.')
        {
            *pfunc = 0;
            lua_pushstring(L, class_name);
            lua_gettable(L, -2);
            *pfunc = '.';
            if(lua_isnil(L, -1))
            {
                return 0;
            }
    	    lua_remove(L, -2);//弹出table
            class_name = pfunc + 1;
        }
        pfunc++;
    }
    if(class_name == start)
    {
        lua_getglobal(L, class_name);
        if(lua_isnil(L, -1))
        {
            return 0;
        }
    }else
    {
        lua_pushstring(L, class_name);
        lua_gettable(L, -2);
        if(lua_isnil(L, -1))
        {
            return 0;
        }
        lua_remove(L, -2);//弹出table
    }
    return 1;     
}


//消息分发
static void on_read(int sockfd)
{
    //填充recvbuf
    char* buf = Recvbuf::getwptr(sockfd);
    int bufremain = Recvbuf::bufremain(sockfd);
    LOG_LOG("bufremain(%d)", bufremain);
    int recv = Port::recv(sockfd, buf, bufremain);
    LOG_LOG("recv(%d)", recv);
    if (recv == 0)
    {
        return;
    }
    if (recv == -1) 
    {
        Port::close(sockfd, "");
        return;
    }
    Port::Port* port = Port::sock2port(sockfd);
    lua_State* L = port->L;
    Recvbuf::wskip(sockfd, recv);
    //拆包
    for(;;)
    {
        //读buf
        int datalen = Recvbuf::datalen(sockfd);
        if(datalen <= sizeof(int))
        {
            break;
        }
        int plen = Recvbuf::getint32(sockfd);
        LOG_LOG("plen(%d) datalen(%d)", plen, datalen);
        if(datalen < plen) 
        {
            break;
        }
        int arfd = Ar::create(Recvbuf::getrptr(sockfd), datalen);
        plen = Ar::readint32(arfd);
        int proto = Ar::readint8(arfd);
        int argcount = Ar::readint16(arfd);
        if (argcount > MAX_ARG_COUNT) 
        {
            Port::close(sockfd, "arg count limit reach");
            return;
        }
        LOG_LOG("argcount(%d) plen(%d)", argcount, plen);
        //分发到不同的协议层
        if(proto == POST_PROTO)
        {
            lua_pushluafunction(L, "Postproto.dispatch");
        }
        for(int i = 0; i < argcount; i++)
        {
            int tag = Ar::readint8(arfd);
            if (tag == INT_TYPE)
            {
                int val = Ar::readint32(arfd);
                lua_pushnumber(L, val);
            }else if (tag == NIL_TYPE)
            {
                lua_pushnil(L);
            }
            else if (tag == STR_TYPE)
            {
                int str_len = Ar::readint16(arfd);
                char *str = Ar::getptr(arfd);
                lua_pushlstring(L, str, str_len);
                Ar::skip(arfd, str_len);
            }
            else if (tag == JSON_TYPE)
            {
                int str_len = Ar::readint16(arfd);
                char *str = Ar::getptr(arfd);
                char c = str[str_len];
                str[str_len] = 0;
                Json::decode(L, str);
                str[str_len] = c;
                Ar::skip(arfd, str_len);
            }
            else if (tag == PROTOBUF_TYPE)
            {
                int msgname_len = Ar::readint16(arfd);
                char *msgname = Ar::getptr(arfd);
                Ar::skip(arfd, msgname_len);

                int buflen = Ar::readint16(arfd);
                char* buf = Ar::getptr(arfd);
                LOG_LOG(msgname);
            }
        }
        LOG_LOG("rskip(%d)", plen);
        Ar::free(arfd);
        Recvbuf::rskip(sockfd, plen);
    }
    Recvbuf::buf2line(sockfd);
}

int calc_len(lua_State* L)
{
    int len = 4 + 2 + 2;
    int argcount = lua_gettop(L) - 2;
    for (int i = 2; i < argcount + 2; i++) 
    { 
        if(lua_isnil(L, i))
        {
            len = len + 1;
        }else if(lua_isnumber(L, i)) 
        {
            len = len + 1 + 4;
        }
        else if(lua_isstring(L, i)) 
        {
            size_t str_len = 0;
            char* str = (char *)lua_tolstring(L, i, &str_len);
            len = len + 1 + 2 + str_len;
        }else if(lua_istable(L, i)) 
        {
            lua_pushvalue(L, i);
            char* str = Json::encode(L);
            lua_pop(L, 1);
            len = len + 1 + 2 + strlen(str);
        }else if(lua_isuserdata(L, i)) 
        {
            ::google::protobuf::Message *msg = (::google::protobuf::Message *)lua_touserdata(L, i);
            len = len + 1 + 2 + strlen(msg->GetTypeName().data());
            len = len + 2 + msg->ByteSize();
        }
    }
    return len;
}

static int send(lua_State* L)
{
    int sockfd = (int)lua_tointeger(L, 1);
    int proto = (int)lua_tointeger(L, 2);
    int argcount = lua_gettop(L) - 2;
    int plen = 4 + calc_len(L);
    LOG_LOG("[SEND] plen(%d) argcount(%d) sockfd(%d)", plen, argcount, sockfd);
    char* buf = Sendbuf::alloc(sockfd, plen);
    int arfd = Ar::create(buf, plen);
    Ar::writeint32(arfd, plen);
    Ar::writeint16(arfd, proto);
    Ar::writeint16(arfd, argcount);
    for (int i = 2; i < argcount + 2; i++) 
    {
        //LOG_LOG("write type(%s)", lua_type(i));
        if(lua_isnil(L, i))
        {
            Ar::writeint8(arfd, NIL_TYPE);
        }else if(lua_isnumber(L, i)) 
        {
            int val = (int)lua_tonumber(L, i);
            Ar::writeint8(arfd, INT_TYPE);
            Ar::writeint32(arfd, val);
        }else if(lua_isstring(L, i)) 
        {
            size_t str_len = 0;
            char* str = (char *)lua_tolstring(L, i, &str_len);
            Ar::writeint8(arfd, STR_TYPE);
            Ar::writelstr(arfd, str, str_len);
        }else if(lua_istable(L, i)) 
        {
            lua_pushvalue(L, i);
            char* str = Json::encode(L);
            lua_pop(L, 1);
            Ar::writeint8(arfd, JSON_TYPE);
            Ar::writelstr(arfd, str);
        }else if(lua_isuserdata(L, i)) 
        {
            //protobuf
            Ar::writeint8(arfd, PROTOBUF_TYPE);
            ::google::protobuf::Message *msg = (::google::protobuf::Message *)lua_touserdata(L, i);
            Ar::writelstr(arfd, msg->GetTypeName().c_str(), msg->GetTypeName().length());
            int msgsize = msg->ByteSize();
            Ar::writeint16(arfd, msgsize);
            char* buf = Ar::getptr(arfd);
            msg->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
            Ar::skip(arfd, msgsize);
            LOG_LOG(msg->GetTypeName().data());
        }
    }
    Sendbuf::flush(sockfd, buf, plen);
    Ar::free(arfd);
    Port::add_write_event(sockfd);
    return 0;
}
