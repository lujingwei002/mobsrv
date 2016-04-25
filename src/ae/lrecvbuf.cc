#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
/*
 *  Recvbuf.create(sockfd, size)
 *  Recvbuf.free(sockfd)
 */

#define int8 char
#define int16 short
#define int32 int
#define int64 long long

#define uint16 unsigned short
#define uint32 unsigned short

typedef struct RBuf{
	int buf_len;
    int rptr;
    int wptr;
	char *buf;
}RBuf;

//1M * 4 * 4 = 16M
#define MAX_SOCKET 1048576

static RBuf rbufs[MAX_SOCKET];

static int mem_total = 0;

#define fd2rbuf(sockfd)  (&rbufs[sockfd])

#define assert_sockfd(sockfd) if(sockfd <= 0 || sockfd >= MAX_SOCKET){\
                        printf("sockfd(%d) is invalid", sockfd);\
                        return 0;\
                     }

static int get_buf(int sockfd, void *vbuf, int buf_len){
    RBuf *self = fd2rbuf(sockfd);
    char *buf = self->buf + self->rptr;
    memcpy(vbuf, buf, buf_len);
    return buf_len;
}

static int read_buf(int sockfd, void *vbuf, int buf_len){
    RBuf *self = fd2rbuf(sockfd);
    char *buf = self->buf + self->rptr;
    memcpy(vbuf, buf, buf_len);
    self->rptr += buf_len;
    return buf_len;
}

int recvbuf_free(int sockfd)
{
    return 0;
}

static int lfree(lua_State *L){
    return 0;
}

static int lbufremain(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    assert_sockfd(sockfd);
    RBuf *self = fd2rbuf(sockfd);
    //printf("sockfd(%d) bufremain buf_len(%d) wptr(%d)\n", sockfd, self->buf_len, self->wptr);
    lua_pushinteger(L, self->buf_len - self->wptr);
    return 1;
}

static int lbuflen(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    assert_sockfd(sockfd);
    RBuf *self = fd2rbuf(sockfd);
    return self->buf_len;
}

static int ldatalen(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    assert_sockfd(sockfd);
    RBuf *self = fd2rbuf(sockfd);
    int datalen = self->wptr - self->rptr;
    lua_pushinteger(L, datalen);
    return 1;
}

static int lgetrptr(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    assert_sockfd(sockfd);
    RBuf *self = fd2rbuf(sockfd);
    char *ptr = self->buf + self->rptr;
    lua_pushlightuserdata(L, ptr);
    return 1;
}

static int lfind(lua_State *L) {
    int sockfd;
    size_t str_len;
    char *str;
    int startpos;
    int i;
    sockfd = (int)lua_tointeger(L, 1);
    str = (char *)lua_tolstring(L, 2, &str_len);
    if (lua_isnumber(L, 3)) {
        startpos = (int)lua_tointeger(L, 3);
    } else {
        startpos = 0;
    } 
    RBuf *self = fd2rbuf(sockfd);
    if (self->rptr + (int)str_len >= self->wptr) {
    //    printf("rptr(%d) str_len(%d) wptr(%d)\n", self->rptr, str_len, self->wptr);
        return 0;
    }
    //printf("i(%d) wptr(%d)\n", self->rptr + startpos, self->wptr);
    for (i = self->rptr + startpos; i < self->wptr; i++) {
        if (!strncmp(self->buf + i, str, str_len)) {
            lua_pushinteger(L, i - self->rptr);
            return 1;
        }
     //   printf("ee %d c(%c)\n", i, *(self->buf + i));
    }
    return 0;
}
/*
 * @arg1 sockfd
 */
static int lgetwptr(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    RBuf *self = fd2rbuf(sockfd);
    char *ptr = self->buf + self->wptr;
    lua_pushlightuserdata(L, ptr);
    return 1;
}

static int lrskip(lua_State *L){
    int sockfd;
    int len;
    sockfd = (int)lua_tointeger(L, 1);
    len = (int)lua_tointeger(L, 2);
    RBuf *self = fd2rbuf(sockfd);
    if (self->wptr - self->rptr < len) {
        return 0;
    }
    self->rptr += len;
    lua_pushinteger(L, len);
    return 1;
}

static int lwskip(lua_State *L){
    int sockfd;
    int len;
    sockfd = (int)lua_tointeger(L, 1);
    len = (int)lua_tointeger(L, 2);
    RBuf *self = fd2rbuf(sockfd);
    self->wptr += len;
    lua_pushinteger(L, len);
    return 1;
}
 
static int lbuf2line(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    RBuf *self = fd2rbuf(sockfd);
    if(self->rptr == 0) {
        return 0;
    }
    int len = self->wptr - self->rptr;
    memmove(self->buf, self->buf + self->rptr, len);
    self->rptr = 0;
    self->wptr = len;
    return 0;
}

static int lreadbuf(lua_State *L){
    int sockfd;
    int buflen;
    sockfd = (int)lua_tointeger(L, 1);
    buflen = (int)lua_tointeger(L, 2);
    RBuf *self = fd2rbuf(sockfd);
    if (self->wptr - self->rptr < buflen) {
        return 0;
    }
    lua_pushlstring(L, self->buf + self->rptr, buflen);
    self->rptr += buflen;
    return 1;
}

static int lreadint8(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int8 val = 0;
    read_buf(sockfd, (char *)&val, sizeof(int8));
    lua_pushinteger(L, val);
    return 1;
}

static int lreadint16(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int16 val = 0;
    read_buf(sockfd, (char *)&val, sizeof(int16));
    lua_pushinteger(L, val);
    return 1;
}

static int lreadint32(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int32 val = 0;
    read_buf(sockfd, (char *)&val, sizeof(int32));
    lua_pushinteger(L, val);
    return 1;
}

static int lgetint8(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int8 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(int8));
    lua_pushinteger(L, val);
    return 1;
}

static int lgetuint32(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    uint32 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(uint32));
    lua_pushinteger(L, val);
    return 1;
}



static int lgetuint16(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    uint16 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(uint16));
    lua_pushinteger(L, val);
    return 1;
}


static int lgetint16(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int16 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(int16));
    lua_pushinteger(L, val);
    return 1;
}

static int lgetint32(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int32 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(int32));
    lua_pushinteger(L, val);
    return 1;
}

int recvbuf_create(int sockfd, int size){
    RBuf *self = fd2rbuf(sockfd);
    if(self->buf_len < size){
        if(self->buf != NULL){
            free(self->buf);
            self->buf_len = 0;
            self->buf = NULL;
            mem_total -= self->buf_len;
        }
        self->buf = (char *)malloc(size);
        if(self->buf == NULL){
            printf("malloc fail");
            return 1;
        }
        self->buf_len = size;
        mem_total += size;
    }
    self->rptr = 0;
    self->wptr = 0;
    //printf("recvbuf create sockfd(%d) buf_len(%d)\n", sockfd, self->buf_len);
    return 0;
}

static int lcreate(lua_State *L){
    int sockfd;
    int size;
    sockfd = (int)lua_tointeger(L, 1);
    size = (int)lua_tointeger(L, 2);
    if (recvbuf_create(sockfd, size)) {
        return 0;
    }
    lua_pushboolean(L, 1);
    return 1;
}

static int ltest(lua_State *L){
    printf("test\n");
    return 0;
}

static luaL_Reg lua_lib[] ={
    {"test", ltest},
    {"create", lcreate},
    {"free", lfree},
    {"readint8", lreadint8},
    {"readint16", lreadint16},
    {"readint32", lreadint32},
    {"readbuf", lreadbuf},
    {"getint8", lgetint8},
    {"getint16", lgetint16},
    {"getint32", lgetint32},
    {"getuint16", lgetuint16},
    {"getuint32", lgetuint32},
    {"buf2line", lbuf2line},
    {"wskip", lwskip},
    {"rskip", lrskip},
    {"getwptr", lgetwptr},
    {"getrptr", lgetrptr},
    {"datalen", ldatalen},
    {"buflen", lbuflen},
    {"find", lfind},
    {"bufremain", lbufremain},
    {NULL, NULL}
};

int luaopen_recvbuf(lua_State *L){
	luaL_register(L, "Recvbuf", lua_lib);
	return 1;
}
