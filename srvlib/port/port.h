#ifndef _PORT_H_
#define _PORT_H_

#include "net/ae.h"

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


//一个管理SOCKET的模块， 但解包已经不在C层了，
/*
Thu Oct  1 09:08:23 CST 2015
还是将BUF移进来吧，效率高点, 减少穿越次数
*/

namespace Port 
{

    typedef int ae_read_func(int sockfd, const char* data, int datalen);
    typedef void ae_write_func(int sockfd);

    typedef struct Port
    {
        lua_State *L;  
        struct aeEventLoop *loop;
        void *userdata;
        ae_read_func* on_read;
        ae_write_func* on_write;
        char lua_on_packet[128];
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

    int remove_write_event(int sockfd);
    int add_write_event(int sockfd);
    int listen(Port* port, unsigned short listenport);
    const char* getpeerip(int sockfd);;
    int getpeerport(int sockfd);
    int syncconnect(Port* port, const char* ip, unsigned short portnum);
    int connect(Port* port, const char* ip, unsigned short portnum);
    int free(Port* port);
    int rename(Port* port, const char *name);
    int getsrvid(int sockfd);
    int setsrvid(int sockfd, int srvid);
    int getuserdata(int sockfd);
    int setuserdata(int sockfd, int userdata);
    int setuid(int sockfd, int uid);
    int close(int sockfd, const char *reason);
    int shutdown(int sockfd);
    Port* create(struct aeEventLoop* loop);
    int send(int sockfd, char *buf, int buflen);
    int recv(int sockfd, char *buf, int buflen);
    Port* sock2port(int sockfd);

    int set_read_func(Port* port, ae_read_func* func);
    int set_write_func(Port* port, ae_read_func* func);
};

#endif

