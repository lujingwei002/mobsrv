#ifndef _SENDBUF_H_
#define _SENDBUF_H_

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
/* 
 * rptr rlen rskip 配合使用，用于写socket
 * rptr = SendBuf.rptr()
 * rlen = SendBuf.datalen()
 * sent = send sockfd rptr rlen
 * SendBuf.rskip(sent)
 *
 * flush 和 alloc配合使用, 用于写buff
 * buf = SendBuf.alloc(sockfd, size)
 * write buf
 * SendBuf.flush(sockfd, buf, len)
 *
 */
namespace Sendbuf {
    int datalen(int sockfd);
    int skip_read_ptr(int sockfd, int len);
    char* get_read_ptr(int sockfd);
    int flush(int sockfd, char *buf, int buf_len);
    char* alloc(int sockfd, int need_size);
    int create(int sockfd);
    int free(int sockfd);
};

int luaopen_sendbuf(lua_State *L);

#endif
