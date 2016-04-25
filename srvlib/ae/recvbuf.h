#ifndef _RECVBUF_H_
#define _RECVBUF_H_
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

    int8 readint8(int sockfd);
    int16 readint16(int sockfd);
    int32 readint32(int sockfd);
    uint16 getuint16(int sockfd);
    uint32 getuint32(int sockfd);
    int8 getint8(int sockfd);
    int16 getint16(int sockfd);
    int32 getint32(int sockfd);

};
int luaopen_recvbuf(lua_State *L);

#endif
