#ifndef _SENDBUF_H_
#define _SENDBUF_H_

int sendbuf_create(int sockfd);
int sendbuf_free(int sockfd);
char* sendbuf_get_read_ptr(int sockfd);
int sendbuf_datalen(int sockfd);
int sendbuf_skip_read_ptr(int sockfd, int len);
int sendbuf_flush(int sockfd, char *buf, int buf_len);
char * sendbuf_alloc(int sockfd, int need_size);
int luaopen_sendbuf(lua_State *L);

#endif
