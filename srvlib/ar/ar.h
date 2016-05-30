#ifndef _AR_H_
#define _AR_H_

#include <stdint.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace Ar 
{
    int create(char *buf, int buf_len);
    int free(int fd);

    int rewind(int fd);
    int skip(int fd, int len);

    int datalen(int fd);
    int remain(int fd);
    char* getptr(int fd);
    int test();
    char* malloc(int len); 
    int find(int fd, const char *str, int startpos); 

    int writebuf(int fd, const char* buf, int len);
    int writelstr(int fd, const char* str);
    int writelstr(int fd, const char* str, int len);
    int writeint8(int fd, int8_t val);
    int writeint16(int fd, int16_t val);
    int writeint32(int fd, int32_t val);
    int writeint64(int fd, int64_t val);

    int readbuf(int fd, char* str, int len);
    int readlstr(int fd, char* str, int len);
    int readuint8(int fd);
    int readint8(int fd);
    int readint16(int fd);
    int readint32(int fd);
    int readint64(int fd);

    int lreadstr(lua_State *L);
    int lreadlstr(lua_State *L);
};

#endif
