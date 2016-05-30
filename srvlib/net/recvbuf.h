#ifndef _RECVBUF_H_
#define _RECVBUF_H_
#include <stdint.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
/*
 *  Recvbuf.create(sockfd, size)
 *  Recvbuf.free(sockfd)
*/

namespace  Recvbuf
{
    int create(int sockfd, int size);
    int free(int sockfd);
    int buf2line(int sockfd);
    int wskip(int sockfd, int len);
    int rskip(int sockfd, int len);
    char* getwptr(int sockfd);
    char* getrptr(int sockfd);
    int find(int sockfd, const char *str, int startpos); 
    int datalen(int sockfd);
    int buflen(int sockfd);
    int bufremain(int sockfd);

    int8_t readint8(int sockfd);
    int16_t readint16(int sockfd);
    int32_t readint32(int sockfd);
    uint16_t getuint16(int sockfd);
    uint32_t getuint32(int sockfd);
    int8_t getint8(int sockfd);
    int16_t getint16(int sockfd);
    int32_t getint32(int sockfd);

};
int luaopen_recvbuf(lua_State *L);

#endif
