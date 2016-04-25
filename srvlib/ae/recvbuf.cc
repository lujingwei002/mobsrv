#include "stdafx.h"

namespace Recvbuf 
{ 

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
#define fd2rbuf(sockfd)  (&Recvbuf::rbufs[sockfd])

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

int free(int sockfd) {
    return 0;
}


int bufremain(int sockfd){
    RBuf *self = fd2rbuf(sockfd);
    return self->buf_len - self->wptr;
}

int buflen(int sockfd){
    RBuf *self = fd2rbuf(sockfd);
    return self->buf_len;
}

int datalen(int sockfd){
    RBuf *self = fd2rbuf(sockfd);
    int datalen = self->wptr - self->rptr;
    return datalen;
}

int find(int sockfd, const char *str, int startpos) 
{
    size_t str_len;
    int i;
    str_len = strlen(str);
    RBuf *self = fd2rbuf(sockfd);
    if (self->rptr + (int)str_len >= self->wptr) 
    {
    //  LOG("rptr(%d) str_len(%d) wptr(%d)", self->rptr, str_len, self->wptr);
        return -1;
    }
    //LOG("i(%d) wptr(%d)", self->rptr + startpos, self->wptr);
    for (i = self->rptr + startpos; i < self->wptr; i++) 
    {
        if (!strncmp(self->buf + i, str, str_len)) 
        {
            return i - self->rptr;
        }
     // printf("ee %d c(%c)", i, *(self->buf + i));
    }
    return -1;
}

char* getrptr(int sockfd)
{
    RBuf *self = fd2rbuf(sockfd);
    char *ptr = self->buf + self->rptr;
    return ptr;
}


char* getwptr(int sockfd)
{
    RBuf *self = fd2rbuf(sockfd);
    char *ptr = self->buf + self->wptr;
    return ptr;
}

int rskip(int sockfd, int len)
{
    RBuf *self = fd2rbuf(sockfd);
    if (self->wptr - self->rptr < len) 
    {
        return 0;
    }
    self->rptr += len;
    return len;
}

int wskip(int sockfd, int len)
{
    RBuf *self = fd2rbuf(sockfd);
    self->wptr += len;
    return len;
}
 
int buf2line(int sockfd)
{
    RBuf *self = fd2rbuf(sockfd);
    if(self->rptr == 0) {
        return 1;
    }
    int len = self->wptr - self->rptr;
    memmove(self->buf, self->buf + self->rptr, len);
    self->rptr = 0;
    self->wptr = len;
    return 0;
}

int8 readint8(int sockfd)
{
    int8 val = 0;
    read_buf(sockfd, (char *)&val, sizeof(int8));
    return val;
}

int16 readint16(int sockfd)
{
    int16 val = 0;
    read_buf(sockfd, (char *)&val, sizeof(int16));
    return val;
}

int32 readint32(int sockfd)
{
    int32 val = 0;
    read_buf(sockfd, (char *)&val, sizeof(int32));
    return val;
}

int8 getint8(int sockfd)
{
    int8 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(int8));
    return val;
}

uint32 getuint32(int sockfd)
{
    uint32 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(uint32));
    return val;
}

uint16 getuint16(int sockfd)
{
    uint16 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(uint16));
    return val;
}

int16 getint16(int sockfd)
{
    int16 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(int16));
    return val;
}

int32 getint32(int sockfd)
{
    int32 val = 0;
    get_buf(sockfd, (char *)&val, sizeof(int32));
    return val;
}

int create(int sockfd, int size)
{
    RBuf *self = fd2rbuf(sockfd);
    
    if(self->buf_len < size)
    {
        if(self->buf != NULL)
        {
            ::free(self->buf);
            self->buf_len = 0;
            self->buf = NULL;
            mem_total -= self->buf_len;
        }
        self->buf = (char *)malloc(size);
        if(self->buf == NULL)
        {
            printf("malloc fail");
            return 1;
        }
        self->buf_len = size;
        mem_total += size;
    }
    self->rptr = 0;
    self->wptr = 0;
    LOG_LOG("recvbuf create sockfd(%d) buf_len(%d)", sockfd, self->buf_len);
    return 0;
}

};

static int lreadbuf(lua_State *L)
{
    int sockfd;
    int buflen;
    sockfd = (int)lua_tointeger(L, 1);
    buflen = (int)lua_tointeger(L, 2);
    Recvbuf::RBuf *self = fd2rbuf(sockfd);
    if (self->wptr - self->rptr < buflen) 
    {
        return 0;
    }
    lua_pushlstring(L, self->buf + self->rptr, buflen);
    self->rptr += buflen;
    return 1;
}


static int lgetwptr(lua_State *L)
{
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    Recvbuf::RBuf *self = fd2rbuf(sockfd);
    char *ptr = self->buf + self->wptr;
    lua_pushlightuserdata(L, ptr);
    return 1;
}


static int lgetrptr(lua_State *L)
{
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    Recvbuf::RBuf *self = fd2rbuf(sockfd);
    char *ptr = self->buf + self->rptr;
    lua_pushlightuserdata(L, ptr);
    return 1;
}


static int lfree(lua_State *L){
    return 0;
}

static int ltest(lua_State *L){
    LOG_LOG("test\n");
    return 0;
}

static int lbufremain(lua_State* L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int len = Recvbuf::bufremain(sockfd);
    lua_pushinteger(L, len);
    return 1;
}

static int lfind(lua_State *L) {
    int sockfd;
    size_t str_len;
    char *str;
    int startpos;
    sockfd = (int)lua_tointeger(L, 1);
    str = (char *)lua_tolstring(L, 2, &str_len);
    if (lua_isnumber(L, 3)) {
        startpos = (int)lua_tointeger(L, 3);
    } else {
        startpos = 0;
    } 
    int pos = Recvbuf::find(sockfd, str, startpos);
    lua_pushinteger(L, pos);
    return 1;
}

static int lbuflen(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int len = Recvbuf::buflen(sockfd);
    lua_pushinteger(L, len);
    return 1;
}

static int ldatalen(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int len = Recvbuf::datalen(sockfd);
    lua_pushinteger(L, len);
    return 1;
} 

static int lrskip(lua_State *L)
{
    int sockfd;
    int len;
    sockfd = (int)lua_tointeger(L, 1);
    len = (int)lua_tointeger(L, 2);
    int result = Recvbuf::rskip(sockfd, len);
    lua_pushinteger(L, result);
    return 1;
} 

static int lwskip(lua_State *L)
{
    int sockfd;
    int len;
    sockfd = (int)lua_tointeger(L, 1);
    len = (int)lua_tointeger(L, 2);
    int result = Recvbuf::wskip(sockfd, len);
    lua_pushinteger(L, result);
    return 1;
} 

static int lbuf2line(lua_State *L)
{
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    if(Recvbuf::buf2line(sockfd)) 
    {
        return 0;
    }
    lua_pushboolean(L, 1);
    return 1;
} 

static int lcreate(lua_State *L){
    int sockfd;
    int size;
    sockfd = (int)lua_tointeger(L, 1);
    size = (int)lua_tointeger(L, 2);
    if (Recvbuf::create(sockfd, size)) {
        return 0;
    }
    lua_pushboolean(L, 1);
    return 1;
}

static int lreadint8(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    lua_pushinteger(L, Recvbuf::readint8(sockfd));
    return 1;
}

static int lreadint16(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    lua_pushinteger(L, Recvbuf::readint16(sockfd));
    return 1;
}

static int lreadint32(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    lua_pushinteger(L, Recvbuf::readint32(sockfd));
    return 1;
}

static int lgetint8(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    lua_pushinteger(L, Recvbuf::getint8(sockfd));
    return 1;
}

static int lgetint16(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    lua_pushinteger(L, Recvbuf::getint16(sockfd));
    return 1;
}

static int lgetint32(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    lua_pushinteger(L, Recvbuf::getint32(sockfd));
    return 1;
}

static int lgetuint16(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    lua_pushinteger(L, Recvbuf::getuint16(sockfd));
    return 1;
}

static int lgetuint32(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    lua_pushinteger(L, Recvbuf::getuint32(sockfd));
    return 1;
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

