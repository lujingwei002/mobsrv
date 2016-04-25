#include "stdafx.h"

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

static void on_read(int sockfd)
{
    char* buf = Recvbuf::getwptr(sockfd);
    int bufremain = Recvbuf::bufremain(sockfd);
    LOG_LOG("bufremain(%d)", bufremain);
    int recv = Port::recv(sockfd, buf, bufremain);
    LOG_LOG("recv(%d)", recv);
    if (recv == 0)
    {
        return;
    }
    if(recv == -1)
    {
        Port::close(sockfd, "");
        return;
    }
    Recvbuf::wskip(sockfd, recv);
    //读buf
    int pos = Recvbuf::find(sockfd, "\r\n", 0);
    if (pos < 0)
    {
        LOG_LOG("data not enough");
        return;
    }
    LOG_LOG("recv str pos(%d)", pos);
    Port::Port* port = Port::sock2port(sockfd);
    lua_State* L = port->L;
    if(port->lua_on_read[0] != 0)
    {
        lua_pushluafunction(L, port->lua_on_read);
        lua_pushnumber(L, sockfd);
        lua_pushlstring(L, Recvbuf::getrptr(sockfd), pos);
        if (lua_pcall(L, 2, 0, 0) != 0)
        {
            LOG_ERROR("error running function %s: %s\n", port->lua_on_read, lua_tostring(L, -1));
            lua_printstack(L);
        }
        lua_pop(L, lua_gettop(L));
    }
    Recvbuf::rskip(sockfd, 2);
    Recvbuf::buf2line(sockfd);
    /* 
    local fn = loadstring(str)
    if fn then
        fn()
    end
    */
}

static int lreply(lua_State *L)
{
    return 0;
}

static int lcreate(lua_State *L)
{
    if(lua_isuserdata(L, 1)){
        struct aeEventLoop *loop = (struct aeEventLoop *)lua_touserdata(L, 1);
        Port::Port *port = Port::create(loop);
        port->L = L;
        Port::set_read_func(port, on_read);
        lua_pushlightuserdata(L, port);
        return 1;
    }
    return 0;
}


static luaL_Reg lua_lib[] = {
    {"create", lcreate},
    {"reply", lreply},
    {NULL, NULL}
};

int luaopen_strport(lua_State *L){
	luaL_register(L, "Strport", (luaL_Reg*)lua_lib);
    return 1;
}

