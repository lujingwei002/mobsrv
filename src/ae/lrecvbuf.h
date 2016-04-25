#ifndef _RECVBUF_H_
#define _RECVBUF_H_

int recvbuf_create(int sockfd, int size);
int recvbuf_free(int sockfd);
int recvbuf_bufremain(int sockfd);
int recvbuf_buflen(int sockfd);
int recvbuf_datalen(int sockfd);

int luaopen_recvbuf(lua_State *L);
#endif
