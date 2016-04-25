#include "ar.h"
#include <stdlib.h>
#include <string.h>

#define uint8 unsigned char

#define int8 char
#define int16 short
#define int32 int
#define int64 long long

/*
 *   local arfd = Ar.create(buf, buflen)
 *   local uid = Ar.read_int(arfd)
 *   local uname = Ar.read_str(arfd)
 */

#define MAX_AR 64
static ar_t s_ars[MAX_AR];
#define fd2ar(fd)  (&s_ars[fd])

int ar_create(char *buf, int buf_len){
    int fd = 0;
    int i;
    for(i = 1; i < MAX_AR; i++)
    {
        if(s_ars[i].used == 0)
        {   
            fd = i;
            s_ars[i].used = 1;
            s_ars[i].buf = buf;
            s_ars[i].buf_len = buf_len;
            s_ars[i].rptr = 0;
            break;
        }
    }
    return fd;
}

static int lrewind(lua_State *L){
    int fd = (int)lua_tointeger(L, 1);
    ar_t *self = fd2ar(fd);
    self->rptr = 0;
    return 0;
}

static int ldatalen(lua_State *L){
    int fd = (int)lua_tointeger(L, 1);
    ar_t *self = fd2ar(fd);
    lua_pushinteger(L, self->rptr);
    return 1;
}

static int lremain(lua_State *L){
    int fd = (int)lua_tointeger(L, 1);
    ar_t *self = fd2ar(fd);
    lua_pushinteger(L, self->buf_len - self->rptr);
    return 1;
}

static int lgetptr(lua_State *L){
    int fd = (int)lua_tointeger(L, 1);
    ar_t *self = fd2ar(fd);
    lua_pushlightuserdata(L, self->buf + self->rptr);
    return 1;
}

static int ar_write(int fd, void *vbuf, size_t buf_len){
    ar_t *self = fd2ar(fd);
    if (self->buf_len - self->rptr < buf_len) {
        return 0;
    }
    char *buf = self->buf + self->rptr;
    memcpy(buf, vbuf, buf_len);
    self->rptr += buf_len;
    return buf_len;
}

static int ltest(lua_State *L){
    printf("test\n");
    return 0;
}

/*
 * for test
 */
static int lmalloc(lua_State *L) {
    int len = (int)lua_tointeger(L, 1);
    char *buf = (char *)malloc(len);
    lua_pushlightuserdata(L, buf);
    return 1;
}

static int lfree(lua_State *L){
    int fd = (int)lua_tointeger(L, 1);
    ar_t *self = fd2ar(fd);
    self->used = 0;
    return 0;
}

static int lcreate(lua_State *L){
	if (lua_gettop(L) == 2 && lua_isuserdata(L, 1) && lua_isnumber(L, 2)){
        char *buf = (char *)lua_touserdata(L, 1);
        int buf_len = (int)lua_tointeger(L, 2);
        int fd = ar_create(buf, buf_len);
        lua_pushinteger(L, fd);
        return 1;
    }
    return 0;
}

static int lwritestr(lua_State *L){
	if (lua_gettop(L) == 2 && lua_isnumber(L, 1) && lua_isstring(L, 2)){
        char *str;
        size_t str_len;
        int fd = (int)lua_tointeger(L, 1);
        str = (char *)lua_tolstring(L, 2, &str_len);
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < str_len) {
            lua_pushinteger(L, 0); 
            return 1;
        }
        ar_write(fd, str, str_len);
        lua_pushinteger(L, str_len); 
        return 1;
	}
    return 0;
}

static int lwritelstr(lua_State *L){
	if (lua_gettop(L) == 2 && lua_isnumber(L, 1) && lua_isstring(L, 2)){
        int fd = (int)lua_tointeger(L, 1);
        char *str;
        size_t str_len;
        str = (char *)lua_tolstring(L, 2, &str_len);
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < str_len + sizeof(int16)) {
            lua_pushinteger(L, 0); 
            return 1;
        }
        int16 val = str_len;;
        ar_write(fd, (char *)&val, sizeof(int16));
        ar_write(fd, str, str_len);
        lua_pushinteger(L, str_len); 
        return 1;
	}
    return 0;
}

static int lwriteint8(lua_State *L){
	if (lua_gettop(L) == 2 && lua_isnumber(L, 1) && lua_isnumber(L, 2)){
        int fd = (int)lua_tointeger(L, 1);
        int8 val = (int8)lua_tointeger(L, 2);
        ar_write(fd, (char *)&val, sizeof(int8));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}

static int lwriteint16(lua_State *L){
	if (lua_gettop(L) == 2 && lua_isnumber(L, 1) && lua_isnumber(L, 2)){
        int fd = (int)lua_tointeger(L, 1);
        int16 val = (int16)lua_tointeger(L, 2);
        ar_write(fd, (char *)&val, sizeof(int16));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}

static int lwriteint32(lua_State *L){
	if (lua_gettop(L) == 2 && lua_isnumber(L, 1) && lua_isnumber(L, 2)){
        int fd = (int)lua_tointeger(L, 1);
        int32 val = (int32)lua_tointeger(L, 2);
        ar_write(fd, (char *)&val, sizeof(int32));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}

static int lwriteint64(lua_State *L){
	if (lua_gettop(L) == 2 && lua_isnumber(L, 1) && lua_isnumber(L, 2)){
        int fd = (int)lua_tointeger(L, 1);
        int64 val = (int64)lua_tointeger(L, 2);
        ar_write(fd, (char *)&val, sizeof(int64));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}
static int ar_read(int fd, void *vbuf, size_t buf_len){
    ar_t *self = fd2ar(fd);
    if (self->buf_len - self->rptr < buf_len) {
        return 0;
    }
    char *buf = self->buf + self->rptr;
    memcpy(vbuf, buf, buf_len);
    self->rptr += buf_len;
    return buf_len;
}

static int lreadstr(lua_State *L){
    if (lua_gettop(L) == 2 && lua_isnumber(L, 1) && lua_isnumber(L, 2)){
        int fd = (int)lua_tointeger(L, 1);
        size_t str_len = (size_t)lua_tointeger(L, 2);
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < str_len) {
            return 0;
        }
        lua_pushlstring(L, self->buf + self->rptr, str_len);
        self->rptr += str_len;
        return 1;
	}
    return 0;
}


static int lreadlstr(lua_State *L){
    if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
        int fd = (int)lua_tointeger(L, 1);
        ar_t *self = fd2ar(fd);
        int16 str_len;
        if (self->buf_len - self->rptr < sizeof(int16)) {
            return 0;
        }
        str_len = *((int16 *)(self->buf + self->rptr));
        if (self->buf_len - self->rptr < str_len + sizeof(int16)) {
            return 0;
        }
        self->rptr += sizeof(int16);
        lua_pushlstring(L, self->buf + self->rptr, str_len);
        self->rptr += str_len;
        return 1;
	}
    return 0;
}

static int lreaduint8(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
        int fd = (int)lua_tointeger(L, 1);
        uint8 val = 0;
        ar_read(fd, (char *)&val, sizeof(uint8));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}


static int lreadint8(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
        int fd = (int)lua_tointeger(L, 1);
        int8 val = 0;
        ar_read(fd, (char *)&val, sizeof(int8));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}

static int lreadint16(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
        int fd = (int)lua_tointeger(L, 1);
        int16 val = 0;
        ar_read(fd, (char *)&val, sizeof(int16));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}

static int lreadint32(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
        int fd = (int)lua_tointeger(L, 1);
        int32 val = 0;
        ar_read(fd, (char *)&val, sizeof(int32));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}

static int lreadint64(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
        int fd = (int)lua_tointeger(L, 1);
        int64 val = 0;
        ar_read(fd, (char *)&val, sizeof(int64));
        lua_pushinteger(L, val); 
        return 1;
	}
    return 0;
}

static luaL_Reg lua_lib[] = {
    {"malloc",      lmalloc},
    {"create",      lcreate},
    {"free",        lfree},
    {"datalen",     ldatalen},
    {"remain",      lremain},
    {"getptr",      lgetptr},
    {"rewind",      lrewind},
    {"test",        ltest},
    {"readuint8",   lreaduint8},
    {"readint8",    lreadint8},
    {"readint16",   lreadint16},
    {"readint32",   lreadint32},
    {"readint64",   lreadint64},
    {"readlstr",    lreadlstr},
    {"readstr",     lreadstr},

    {"writeint8",   lwriteint8},
    {"writeint16",  lwriteint16},
    {"writeint32",  lwriteint32},
    {"writeint64",  lwriteint64},
    {"writelstr",   lwritelstr},
    {"writestr",    lwritestr},

    {0, 0}
};

extern "C" {
int luaopen_ar(lua_State *L){
	luaL_register(L, "Ar", lua_lib);
    return 1;
}
}
