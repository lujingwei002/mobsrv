#ifndef _PORT_H_
#define _PORT_H_

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include "ae.h"

//一个管理SOCKET的模块， 但解包已经不在C层了，
/*
    1.可写事件要小心用，有数据时才加，否则CPU会空转，但如果跑帧run_once的话不会有问题，
    2.但缓冲层也不在C了，所以会不断调用LUA的事件回调，所以还是有数据才加吧
    
Thu Oct  1 09:08:23 CST 2015
还是将BUF移进来吧，效率高点, 减少穿越次数
*/

typedef struct Port
{
    lua_State *L;  
    struct aeEventLoop *loop;
    void *userdata;
    char lua_on_read[128];
    char lua_on_accept[128];
    char lua_on_close[128];
    char lua_on_connect_err[128];
    char lua_on_connect_suc[128];
    char name[64];
    int timerid;
}Port;

typedef struct Sock
{
    Port* port;
    int sockfd;
    int shutdown; 
    int uid;
    int send_seq; 
    int recv_seq; 
    int userdata;
    int srvid;
}Sock;

int luaopen_port(lua_State *L);

#endif
