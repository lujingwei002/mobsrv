#include "lport.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "lsendbuf.h"
#include "lrecvbuf.h"
#include "log.h"

#define MAX_SOCK 10240
Sock s_socks[MAX_SOCK];
#define fd2sock(fd)  (&s_socks[fd])

#define ERR 1
#define OK 0

//#define LOG_ERROR printf
//#define LOG_LOG printf

static void lua_printstack(lua_State *L) {
    lua_getglobal(L, "debug");  
    lua_getfield(L, -1, "traceback");  
    lua_pcall(L, 0, 1, 0);   
    const char* sz = lua_tostring(L, -1);  
    printf("%s\n", sz);
}

//login.hello_world
//hello_world
static int lua_pushluafunction(lua_State *L, const char *func){
    char *start = (char *)func;
    char *class_name = start;
    char *pfunc = start;
    while(*pfunc != 0){
        if(*pfunc == '.' && class_name == start){
            *pfunc = 0;
            lua_getglobal(L, class_name);
            *pfunc = '.';
            if(lua_isnil(L, -1)){
                return 0;
            }
            class_name = pfunc + 1;
        }else if(*pfunc == '.'){
            *pfunc = 0;
            lua_pushstring(L, class_name);
            lua_gettable(L, -2);
            *pfunc = '.';
            if(lua_isnil(L, -1)){
                return 0;
            }
    	    lua_remove(L, -2);//弹出table
            class_name = pfunc + 1;
        }
        pfunc++;
    }
    if(class_name == start){
        lua_getglobal(L, class_name);
        if(lua_isnil(L, -1)){
            return 0;
        }
    }else{
        lua_pushstring(L, class_name);
        lua_gettable(L, -2);
        if(lua_isnil(L, -1)){
            return 0;
        }
        lua_remove(L, -2);//弹出table
    }
    return 1;     

}

static void setnonblock(int sockfd)
{
    int flags;
    flags = fcntl(sockfd, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(sockfd, F_SETFL, flags);
}

static int sock_create(Port *port, int sockfd)
{
    if(sockfd <= 0 || sockfd >= MAX_SOCK)
    {
        LOG_ERROR("bad fd %d\n", sockfd); 
        return ERR;
    }
    Sock *sock = fd2sock(sockfd);
    bzero(sock, sizeof(Sock));
    sock->port = port;
    sock->sockfd = sockfd;
    recvbuf_create(sockfd, 1024);
    sendbuf_create(sockfd);
    return OK;
}

static int sock_free(int sockfd){
    if(sockfd <= 0 || sockfd >= MAX_SOCK){
        LOG_ERROR("bad fd %d\n", sockfd); 
        return ERR;
    }
    Sock *sock = fd2sock(sockfd);
    bzero(sock, sizeof(Sock));
    recvbuf_free(sockfd);
    sendbuf_free(sockfd);
    return OK;
}

static int real_close(int sockfd, const char *reason){
    if(sockfd <= 0 || sockfd >= MAX_SOCK){
        LOG_ERROR("bad fd %d\n", sockfd); 
        return 1;
    }
    Sock *sock = fd2sock(sockfd);
    Port *port = sock->port;
    lua_State *L = port->L;
    if(port->lua_on_close[0] != 0)
    {
	    struct sockaddr_in addr;	
	    socklen_t addrlen = sizeof(addr);	
        getpeername(sockfd, (struct sockaddr *)&addr, &addrlen);
        lua_pushluafunction(L, port->lua_on_close);
        lua_pushnumber(L, sockfd);
        lua_pushstring(L, inet_ntoa(addr.sin_addr));
        lua_pushnumber(L, ntohs(addr.sin_port));
        lua_pushstring(L, reason);
        if (lua_pcall(L, 4, 0, 0) != 0)
        {
            LOG_ERROR("error running function %s: %s\n", port->lua_on_close, lua_tostring(L, -1));
            lua_printstack(L);
        }
        lua_pop(L, lua_gettop(L));
    }
    //移动事件
    aeDeleteFileEvent(port->loop, sockfd, AE_READABLE);
    aeDeleteFileEvent(port->loop, sockfd, AE_WRITABLE);
    //关闭socket
    close(sockfd);
    sock_free(sockfd);
    return 0;
}

//够数据才回调lua, 避免调用多次无谓的lua
static void port_on_read(struct aeEventLoop *eventLoop, int sockfd, void *args, int event)
{
    Sock *sock = fd2sock(sockfd);
    Port *port = sock->port;
    lua_State *L = port->L;
    if(port->lua_on_read[0] != 0)
    {
        lua_pushluafunction(L, port->lua_on_read);
        lua_pushnumber(L, sockfd);
        if (lua_pcall(L, 1, 0, 0) != 0)
        {
            LOG_ERROR("error running function %s: %s\n", port->lua_on_read, lua_tostring(L, -1));
            lua_printstack(L);
        }
        lua_pop(L, lua_gettop(L));
    }
}

static void port_on_write(struct aeEventLoop *eventLoop, int sockfd, void *args, int event)
{
    Sock *sock = fd2sock(sockfd);
    Port *port = sock->port;
    while(1) 
    {
        int datalen = sendbuf_datalen(sockfd);
        char *rptr = sendbuf_get_read_ptr(sockfd);
        if (datalen == 0) 
        {
            break;
        } else if (datalen > 0) 
        {
            int ir = send(sockfd, rptr, datalen, 0);
            LOG_LOG("real_send(%d)\n", ir);
            if (ir > 0) 
            {
                sendbuf_skip_read_ptr(sockfd, ir);
            } else if (ir == -1 && errno == EAGAIN) 
            {
                break;
            } else if(ir == -1) 
            {
                real_close(sockfd, "peer close");
                break;
            }
        }
    }
    if (sendbuf_datalen(sockfd) <= 0) {
        aeDeleteFileEvent(port->loop, sockfd, AE_WRITABLE);
        if (sock->shutdown == 1) {
            real_close(sockfd, strerror(errno));
        }
    }
}


static void port_on_accept(struct aeEventLoop *eventLoop, int listenfd, void *args, int event)
{
    //printf("port_on_accept\n");
    Port* port = (Port *)args;	
    if(port == NULL)
    {
        LOG_ERROR("null\n");
        return;
    }
    lua_State *L = port->L;
	int sockfd;	
	struct sockaddr_in addr;	
	socklen_t addrlen = sizeof(addr);	
    sockfd = accept(listenfd, (struct sockaddr*)&addr, &addrlen);
    if(sockfd == -1)
    {
        LOG_ERROR("accept fail errno %d %s\n", errno, strerror(errno));
        return;
    }
    //LOG_LOG("%s a client connected ! port(%s) sockfd(%d) handler(%s)\n", port->name, port->name, sockfd, port->lua_on_accept);
    if(port->lua_on_accept[0] == 0)
    {
        close(sockfd);
        return;
    }
    if(sock_create(port, sockfd))
    {   
        LOG_ERROR("port_accept sock is full port(%s), sockfd(%d)\n", port->name, sockfd);
        close(sockfd); 
        return;
    }
    setnonblock(sockfd);
    aeCreateFileEvent(port->loop, sockfd, AE_READABLE, port_on_read, NULL);
    aeCreateFileEvent(port->loop, sockfd, AE_WRITABLE, port_on_write, NULL);

    getpeername(sockfd, (struct sockaddr *)&addr, &addrlen);
    lua_pushluafunction(L, port->lua_on_accept);
    lua_pushnumber(L, sockfd);
    lua_pushstring(L, inet_ntoa(addr.sin_addr));
    lua_pushnumber(L, ntohs(addr.sin_port));
    if (lua_pcall(L, 3, 0, 0) != 0)
    {
        LOG_ERROR("error running function %s: %s\n", port->lua_on_accept, lua_tostring(L, -1));
        lua_printstack(L);
    }
    lua_pop(L, lua_gettop(L));
}

static void port_on_connect_suc(struct aeEventLoop *eventLoop, int sockfd, void *args, int event)
{
    Sock *sock = fd2sock(sockfd);
    Port *port = sock->port;
    lua_State *L = port->L;
    //LOG_ERROR("connect success, but sockfd %d, error %d, strerror:%s\n", sockfd, errno,  strerror(errno));
    aeDeleteFileEvent(port->loop, sockfd, AE_READABLE);
    aeDeleteFileEvent(port->loop, sockfd, AE_WRITABLE);
    aeCreateFileEvent(port->loop, sockfd, AE_READABLE, port_on_read, NULL);
    aeCreateFileEvent(port->loop, sockfd, AE_WRITABLE, port_on_write, NULL);
    if(port->lua_on_connect_suc[0] != 0)
    {
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        getpeername(sockfd, (struct sockaddr *)&addr, &addr_len);
        lua_pushluafunction(L, port->lua_on_connect_suc);
        lua_pushnumber(L, sockfd);
        lua_pushstring(L, inet_ntoa(addr.sin_addr));
        lua_pushnumber(L, ntohs(addr.sin_port));
        if (lua_pcall(L, 3, 0, 0) != 0)
        {
            LOG_ERROR("error running function %s: %s\n", port->lua_on_connect_suc, lua_tostring(L, -1));
            lua_printstack(L);
        }
        lua_pop(L, lua_gettop(L));
    }
}

static void port_on_connect_err(struct aeEventLoop *eventLoop, int sockfd, void *args, int event)
{
    Sock *sock = fd2sock(sockfd);
    Port *port = sock->port;
    //LOG_ERROR("[%s] connect fail\n", port->name);
    lua_State *L = port->L;
    if(port->lua_on_connect_err[0] != 0)
    {
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        getpeername(sockfd, (struct sockaddr *)&addr, &addr_len);
        lua_pushluafunction(L, port->lua_on_connect_err);
        lua_pushnumber(L, sockfd);
        lua_pushstring(L, inet_ntoa(addr.sin_addr));
        lua_pushnumber(L, ntohs(addr.sin_port));
        if (lua_pcall(L, 3, 0, 0) != 0)
        {
            LOG_ERROR("error running function %s: %s\n", port->lua_on_connect_err, lua_tostring(L, -1));
            lua_printstack(L);
        }
        lua_pop(L, lua_gettop(L));
    }
    aeDeleteFileEvent(port->loop, sockfd, AE_READABLE);
    aeDeleteFileEvent(port->loop, sockfd, AE_WRITABLE);
    close(sockfd);
    sock_free(sockfd);
}

static int llisten(lua_State *L)
{
    if(lua_isuserdata(L, 1) && lua_isnumber(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        if(port == NULL)
        {
            LOG_ERROR("bad port\n");
            return 0;
        }
        unsigned short listenport = (unsigned short)lua_tonumber(L, 2);
        int sockfd;
        struct sockaddr_in addr;
        sockfd = socket(AF_INET, SOCK_STREAM, 0);	
        if(sockfd < 0)
        {		
            LOG_ERROR("create socket fail sockfd(%d) err(%s)\n", sockfd, strerror(errno));
            return 0;	
        }	
        if (sock_create(port, sockfd)) {
            LOG_ERROR("socket create  fail sockfd(%d)\n", sockfd);
            close(sockfd);
            return 0;
        }
        bzero((void*)&addr, sizeof(addr));	
        addr.sin_family = AF_INET;	
        addr.sin_addr.s_addr = INADDR_ANY;	
        addr.sin_port = htons(listenport);	
        int reuse = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
        if(bind(sockfd,(struct sockaddr *)&addr,sizeof(addr)) < 0)
        {		
            LOG_ERROR("fail to bind port(%d) err(%s)\n", listenport, strerror(errno));
            return 0;	
        }	
        if(listen(sockfd, 5) < 0)
        {		
            LOG_ERROR("fail to listen sockfd(%d) err(%s)\n", sockfd, strerror(errno));
            return 0;	
        }
        //printf("llisten on %d\n", listenport);
        if (AE_ERR == aeCreateFileEvent(port->loop, sockfd, AE_READABLE, port_on_accept, (void*)port)) {
            LOG_ERROR("listen fail create file event sockfd(%d)\n", sockfd);
            return 0;
        }
        lua_pushboolean(L, 1);
        return 1;
    }
    LOG_ERROR("arg wrong\n");
    return 0;
}


static int lgetpeerip(lua_State *L)
{
    if (lua_isnumber(L, 1))
    {
        int sockfd = (int)lua_tonumber(L, 1);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            return 0;
        }
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        getpeername(sockfd, (struct sockaddr *)&addr, &addr_len);
        lua_pushstring(L, inet_ntoa(addr.sin_addr));
        return 1;
    }
    return 0;
}

static int lgetpeerport(lua_State *L)
{
    if (lua_isnumber(L, 1))
    {
        int sockfd = (int)lua_tonumber(L, 1);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            return 0;
        }
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        getpeername(sockfd, (struct sockaddr *)&addr, &addr_len);
        lua_pushinteger(L, ntohs(addr.sin_port));
        return 1;
    }
    return 0;
}

//同步连接
static int lsyncconnect(lua_State *L){   
    Port *port = (Port *)lua_touserdata(L, 1);
    const char *ip = (const char *)lua_tostring(L, 2);
    unsigned short portnum = (unsigned short)lua_tonumber(L, 3);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    if(inet_addr(ip) != (in_addr_t)-1)
    {
        addr.sin_addr.s_addr = inet_addr(ip);   
    }else
    {
        struct hostent *hostent;
        hostent = gethostbyname(ip);
        if(hostent->h_addr_list[0] == NULL)
        {
            LOG_ERROR("connect fail %s\n", ip);
            return 0;
        }
        //LOG_LOG("ip %s/n", inet_ntoa(*(struct in_addr*)(hostent->h_addr_list[0])));
        memcpy(&addr.sin_addr, (struct in_addr *)hostent->h_addr_list[0], sizeof(struct in_addr));
    } 
    addr.sin_port = htons(portnum);        
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        LOG_ERROR("port_connect create socket fail\n");
        return 0;
    }
    if(sock_create(port, sockfd))
    {
        close(sockfd);
        LOG_ERROR("sockfd reach limit\n");
        return 0;
    }
    int rt = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if(rt < 0)
    {
        close(sockfd);
        LOG_ERROR("port_connect fail errno:%d:%s\n", errno, strerror(errno));
        return 0;
    }
    setnonblock(sockfd);
    aeCreateFileEvent(port->loop, sockfd, AE_READABLE, port_on_read, NULL);
    aeCreateFileEvent(port->loop, sockfd, AE_WRITABLE, port_on_write, NULL);
    lua_pushinteger(L, sockfd);
    return 1;
}

//关闭由ConnectV打开的socket和port
static int lfree(lua_State *L)
{
    Port *port = (Port *)lua_touserdata(L, 1);
    if(port == NULL)
    {
        return 0;
    }
    free(port);
    lua_pushboolean(L, 1);
    return 1;
}

//异步连接
static int lconnect(lua_State *L)
{   
    Port *port = (Port *)lua_touserdata(L, 1);
    if (port == NULL) 
    {
        LOG_ERROR("connect arg wrong\n");
        return 0;
    }
    const char *ip = (const char *)lua_tostring(L, 2);
    unsigned short portnum = (unsigned short)lua_tonumber(L, 3);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    if(inet_addr(ip) != (in_addr_t)-1)
    {
        addr.sin_addr.s_addr = inet_addr(ip);   
    }else
    {
        struct hostent *hostent;
        hostent = gethostbyname(ip);
        if(hostent->h_addr_list[0] == NULL)
        {
            LOG_ERROR("connect fail %s\n", ip);
            return 0;
        }
        //LOG_LOG("ip %s/n", inet_ntoa(*(struct in_addr*)(hostent->h_addr_list[0])));
        memcpy(&addr.sin_addr, (struct in_addr *)hostent->h_addr_list[0], sizeof(struct in_addr));
    } 
    addr.sin_port = htons(portnum);        
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        LOG_ERROR("create socket fail\n");
        return 0;
    }
    if(sock_create(port, sockfd))
    {
        LOG_ERROR("sockfd reach limit\n");
        close(sockfd);
        return 0;
    }
    setnonblock(sockfd);
    //初始化
    aeCreateFileEvent(port->loop, sockfd, AE_READABLE, port_on_connect_err, NULL);
    aeCreateFileEvent(port->loop, sockfd, AE_WRITABLE, port_on_connect_suc, NULL);
    int rt = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if(rt < 0 && errno != EINPROGRESS)
    {
        LOG_ERROR("connect fail errno:%d: %s\n", errno, strerror(errno));
        sock_free(sockfd);
        close(sockfd);
        return 0;
    }
    lua_pushinteger(L, sockfd);
    return 1;
} 

static int lon_read(lua_State *L)
{
    if (lua_gettop(L) == 2 && lua_isuserdata(L, 1) && lua_isstring(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        const char *funcname 	= (const char *)lua_tostring(L, 2);
	    strcpy(port->lua_on_read, funcname);
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lon_connect_err(lua_State *L)
{
    if (lua_gettop(L) == 2 && lua_isuserdata(L, 1) && lua_isstring(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        const char *funcname = (const char *)lua_tostring(L, 2);
	    strcpy(port->lua_on_connect_err, funcname);
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}


static int lon_connect_suc(lua_State *L)
{
    if (lua_gettop(L) == 2 && lua_isuserdata(L, 1) && lua_isstring(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        const char *funcname = (const char *)lua_tostring(L, 2);
	    strcpy(port->lua_on_connect_suc, funcname);
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lrename(lua_State *L)
{
    if (lua_gettop(L) == 2 && lua_isuserdata(L, 1) && lua_isstring(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        const char *name = (const char *)lua_tostring(L, 2);
	    strcpy(port->name, name);
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lon_accept(lua_State *L)
{
    if (lua_gettop(L) == 2 && lua_isuserdata(L, 1) && lua_isstring(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        const char *funcname = (const char *)lua_tostring(L, 2);
	    strcpy(port->lua_on_accept, funcname);
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lgetsrvid(lua_State *L)
{
    if(lua_isnumber(L, 1))
    {
        int sockfd = (int)lua_tonumber(L, 1);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            LOG_ERROR("bad fd %d\n", sockfd);
            return 0;
        }
        Sock *sock = fd2sock(sockfd);
        lua_pushinteger(L, sock->srvid);
        return 1;
    }
    return 0;
}

static int lsetsrvid(lua_State *L)
{
    if(lua_isnumber(L, 1) && lua_isnumber(L, 2))
    {
        int sockfd = (int)lua_tonumber(L, 1);
        int srvid = (int)lua_tonumber(L, 2);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            LOG_ERROR("bad fd %d\n", sockfd);
            return 0;
        }
        Sock *sock = fd2sock(sockfd);
        sock->srvid = srvid;
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lgetuserdata(lua_State *L)
{
    if(lua_isnumber(L, 1))
    {
        int sockfd = (int)lua_tonumber(L, 1);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            LOG_ERROR("bad fd %d\n", sockfd);
            return 0;
        }
        Sock *sock = fd2sock(sockfd);
        lua_pushinteger(L, sock->userdata);
        return 1;
    }
    return 0;
}


static int lsetuserdata(lua_State *L)
{
    if(lua_isnumber(L, 1) && lua_isnumber(L, 2))
    {
        int sockfd = (int)lua_tonumber(L, 1);
        int userdata = (int)lua_tonumber(L, 2);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            LOG_ERROR("bad fd %d\n", sockfd);
            return 0;
        }
        Sock *sock = fd2sock(sockfd);
        sock->userdata = userdata;
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}


static int lsetuid(lua_State *L)
{
    if(lua_isuserdata(L, 1) && lua_isnumber(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        int sockfd = (int)lua_tonumber(L, 2);
        int uid	= (int)lua_tonumber(L, 3);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            LOG_ERROR("bad fd %d\n", sockfd);
            return 0;
        }
        Sock *sock = fd2sock(sockfd);
        if (sock->port != port) 
        {
            LOG_ERROR("diff port %d\n", sockfd);
            return 0;
        }
        sock->uid = uid;
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lclose(lua_State *L){
    if(lua_isuserdata(L, 1) && lua_isnumber(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        int sockfd = (int)lua_tonumber(L, 2);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            LOG_ERROR("bad fd %d\n", sockfd);
            return 0;
        }
        Sock *sock = fd2sock(sockfd);
        if (sock->port != port) 
        {
            LOG_ERROR("diff port %d\n", sockfd);
            return 0;
        }
        char *reason;
        if(lua_isstring(L, 3)) {
            reason = (char *)lua_tostring(L, 3);
        } else {
            reason = strerror(errno);
        }
        real_close(sockfd, reason);
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

//关闭读端，用于服务器主动关闭连接，但还想将数据全部写到客户端，所以只关闭读端
//等数据全部写入后，再关闭
//因为消息包解释已经不在C处理了，所以脚本要去做这个处理
static int lshutdown(lua_State *L)
{
    if(lua_isuserdata(L, 1) && lua_isnumber(L, 2))
    {
        Port *port 	= (Port *)lua_touserdata(L, 1);
        int sockfd = (int)lua_tonumber(L, 2);
        if(sockfd <= 0 || sockfd >= MAX_SOCK)
        {
            LOG_ERROR("bad fd %d\n", sockfd);
            return 0;
        }
        Sock *sock = fd2sock(sockfd);
        aeDeleteFileEvent(port->loop, sockfd, AE_READABLE);
        shutdown(sockfd, SHUT_RD);
        sock->shutdown = 1;
        //加入可写事件，将剩余数据写入
        if (AE_ERR == aeCreateFileEvent(port->loop, sockfd, AE_WRITABLE, port_on_write, NULL)) {

        }
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lon_close(lua_State *L)
{
    if (lua_gettop(L) == 2 && lua_isuserdata(L, 1) && lua_isstring(L, 2))
    {
        Port *port = (Port *)lua_touserdata(L, 1);
        const char *funcname 	= (const char *)lua_tostring(L, 2);
	    strcpy(port->lua_on_close, funcname);
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lcreate(lua_State *L)
{
    if (lua_touserdata(L, 1))
    {
        struct aeEventLoop *loop = (struct aeEventLoop *)lua_touserdata(L, 1);
        Port *port = (Port *)malloc(sizeof(Port));
        bzero(port, sizeof(Port));
        port->loop = loop;
        port->L = L;
        lua_pushlightuserdata(L, port);
        return 1;
    }
    return 0;
}

int lremove_write_event(lua_State *L){
    int sockfd = lua_tointeger(L, 1);
    if(sockfd <= 0 || sockfd >= MAX_SOCK){
        LOG_ERROR("bad fd %d\n", sockfd);
        return 0;
    }
    Sock *sock = fd2sock(sockfd);
    Port *port = sock->port;
    aeDeleteFileEvent(port->loop, sockfd, AE_WRITABLE);
    return 1;
}

int ladd_write_event(lua_State *L){
    int sockfd = lua_tointeger(L, 1);
    if(sockfd <= 0 || sockfd >= MAX_SOCK){
        LOG_ERROR("bad fd %d\n", sockfd);
        return 0;
    }
    Sock *sock = fd2sock(sockfd);
    Port *port = sock->port;
    aeCreateFileEvent(port->loop, sockfd, AE_WRITABLE, port_on_write, NULL);
    return 1;
}

static int lsend(lua_State *L){
    int error;
    int sockfd;
    char *buf;
    size_t len;
    sockfd = (int)lua_tointeger(L, 1);
    buf = (char *)lua_touserdata(L, 2);
    len = (int)lua_tointeger(L, 3);
    error = send(sockfd, buf, len, 0);
    lua_pushinteger(L, error);
    return 1;
}

//特殊处理一下这个recv的返回值，跟系统调用不同
static int lrecv(lua_State *L){
    int result;
    int sockfd;
    char *buf;
    int buflen;
    sockfd = (int)lua_tointeger(L, 1);
    buf = (char *)lua_touserdata(L, 2);
    buflen = (int)lua_tointeger(L, 3);
    result = recv(sockfd, buf, buflen, 0);
    if (result == 0) {
        lua_pushinteger(L, -1);
        lua_pushstring(L, strerror(errno));
        return 2;
    }
    if (result == -1 && errno == EAGAIN) {
        lua_pushinteger(L, 0);
        return 1;
    }
    if (result == -1) {
        lua_pushinteger(L, -1);
        lua_pushstring(L, strerror(errno));
        return 2;
    }
    lua_pushinteger(L, result);
    return 1;
}


static luaL_Reg lua_lib[] = 
{
    {"create", lcreate},
    {"free", lfree},
    {"listen", llisten},
    {"connect", lconnect},
    {"syncconnect", lsyncconnect},
    {"on_read", lon_read},
    {"on_accept", lon_accept},
    {"on_connect_suc", lon_connect_suc},
    {"on_connect_err", lon_connect_err},
    {"on_close", lon_close},
    {"rename", lrename},
    {"close", lclose},
    {"shutdown", lshutdown},
    {"getpeerport", lgetpeerport},
    {"getpeerip", lgetpeerip},
    {"setuid", lsetuid},
    {"setuserdata", lsetuserdata},
    {"getuserdata", lgetuserdata},
    {"setsrvid", lsetsrvid},
    {"getsrvid", lgetsrvid},
    {"remove_write_event", lremove_write_event},
    {"add_write_event", ladd_write_event},
    {"recv", lrecv},
    {"send", lsend},
    {NULL, NULL},
};

int luaopen_port(lua_State *L){
	luaL_register(L, "Port", (luaL_Reg*)lua_lib);
    return 1;
}
