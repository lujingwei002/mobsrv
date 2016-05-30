#include "ar.h"
#include <stdlib.h>
#include <string.h>

/*
 *   local arfd = Ar.create(buf, buflen)
 *   local uid = Ar.read_int(arfd)
 *   local uname = Ar.read_str(arfd)
 */
namespace Ar 
{
    typedef struct ar_t
    {
        char *buf;
        size_t buf_len;
        size_t rptr;
        int used;
    }ar_t;

    #define MAX_AR 64
    static ar_t s_ars[MAX_AR];
    #define fd2ar(fd)  (&s_ars[fd])

   int create(char *buf, int buf_len)
   {
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

    int rewind(int fd)
    {
        ar_t *self = fd2ar(fd);
        self->rptr = 0;
        return 0;
    }

    int datalen(int fd)
    {
        ar_t *self = fd2ar(fd);
        return self->rptr;
    }

    int remain(int fd)
    {
        ar_t *self = fd2ar(fd);
        return self->buf_len - self->rptr;
    }

    char* getptr(int fd)
    {
        ar_t *self = fd2ar(fd);
        return self->buf + self->rptr;
    }

    int write(int fd, const char* vbuf, size_t buf_len){
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < buf_len) {
            return 0;
        }
        char *buf = self->buf + self->rptr;
        memcpy(buf, vbuf, buf_len);
        self->rptr += buf_len;
        return buf_len;
    }

    int test()
    {
        printf("test\n");
        return 0;
    }

    char* malloc(int len) 
    {
        char *buf = (char *)::malloc(len);
        return buf;
    }

    int free(int fd)
    {
        ar_t *self = fd2ar(fd);
        self->used = 0;
        return 0;
    }

    int writebuf(int fd, const char* buf, int len)
    {
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < len) 
        {
            return 0;
        }
        return write(fd, buf, len);
    }

    int writelstr(int fd, const char* str, int str_len)
    {
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < str_len + sizeof(int16_t)) 
        {
            return 0;
        }
        int16_t val = str_len;;
        return write(fd, (char *)&val, sizeof(int16_t)) + write(fd, str, str_len);
    }

    int writelstr(int fd, const char* str)
    {
        size_t str_len = strlen(str);
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < str_len + sizeof(int16_t)) 
        {
            return 0;
        }
        int16_t val = str_len;;
        return write(fd, (char *)&val, sizeof(int16_t)) + write(fd, str, str_len);
    }

    int writeint8(int fd, int8_t val)
    {
        return write(fd, (char *)&val, sizeof(int8_t));
    }

    int writeint16(int fd, int16_t val)
    {
        return write(fd, (char *)&val, sizeof(int16_t));
    }

    int writeint32(int fd, int32_t val)
    {
        return write(fd, (char *)&val, sizeof(int32_t));
    }

    int writeint64(int fd, int64_t val)
    {
        return write(fd, (char *)&val, sizeof(int64_t));
    }

    int read(int fd, void *vbuf, size_t buf_len)
    {
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < buf_len) 
        {
            return 0;
        }
        char *buf = self->buf + self->rptr;
        memcpy(vbuf, buf, buf_len);
        self->rptr += buf_len;
        return buf_len;
    }

    int skip(int fd, int len)
    {
        ar_t *self = fd2ar(fd);
        if (self->buf_len - self->rptr < len) 
        {
            return 0;
        }
        self->rptr += len;
        return len;
    }

    int readbuf(int fd, char* str, int len)
    {
        return read(fd, str, len);
    }

    int readlstr(int fd, char* str, int len)
    {
        ar_t *self = fd2ar(fd);
        int16_t str_len;
        if (self->buf_len - self->rptr < sizeof(int16_t)) 
        {
            return 0;
        }
        str_len = *((int16_t *)(self->buf + self->rptr));
        if (self->buf_len - self->rptr < str_len + sizeof(int16_t)) 
        {
                return 0;
        }
        if (len < str_len + 1) 
        {
            return 0;
        }
        self->rptr += sizeof(int16_t);
        memcpy(str, self->buf + self->rptr, str_len);
        str[str_len] = 0;
        self->rptr += str_len;
        return str_len;
    }
    
    int readuint8(int fd)
    {
        uint8_t val = 0;
        read(fd, (char *)&val, sizeof(uint8_t));
        return val;
    }

    int readint8(int fd)
    {
        int8_t val = 0;
        read(fd, (char *)&val, sizeof(int8_t));
        return val;
    }

    int readint16(int fd)
    {
        int16_t val = 0;
        read(fd, (char *)&val, sizeof(int16_t));
        return val;
    }

    int readint32(int fd)
    {
        int32_t val = 0;
        read(fd, (char *)&val, sizeof(int32_t));
        return val;
    }

    int readint64(int fd)
    {
        int64_t val = 0;
        read(fd, (char *)&val, sizeof(int64_t));
        return val;
    }

    int lreadstr(lua_State *L)
    {
        if (lua_gettop(L) == 2 && lua_isnumber(L, 1) && lua_isnumber(L, 2))
        {
            int fd = (int)lua_tointeger(L, 1);
            size_t str_len = (size_t)lua_tointeger(L, 2);
            ar_t *self = fd2ar(fd);
            if (self->buf_len - self->rptr < str_len) 
            {
                return 0;
            }
            lua_pushlstring(L, self->buf + self->rptr, str_len);
            self->rptr += str_len;
            return 1;
        }
        return 0;
    }

    int lreadlstr(lua_State *L)
    {
        if (lua_gettop(L) == 1 && lua_isnumber(L, 1))
        {
            int fd = (int)lua_tointeger(L, 1);
            ar_t *self = fd2ar(fd);
            int16_t str_len;
            if (self->buf_len - self->rptr < sizeof(int16_t)) 
            {
                return 0;
            }
            str_len = *((int16_t *)(self->buf + self->rptr));
            if (self->buf_len - self->rptr < str_len + sizeof(int16_t)) 
            {
                return 0;
            }
            self->rptr += sizeof(int16_t);
            lua_pushlstring(L, self->buf + self->rptr, str_len);
            self->rptr += str_len;
            return 1;
        }
        return 0;
    }

    int find(int fd, int sockfd, const char *str, int startpos) 
    {
        ar_t *self = fd2ar(fd);
        size_t str_len;
        int i;
        str_len = strlen(str);
        if (self->rptr + (int)str_len >= self->buf_len) 
        {
            return -1;
        }
        for (i = self->rptr + startpos; i < self->buf_len; i++) 
        {
            if (!strncmp(self->buf + i, str, str_len)) 
            {
                return i - self->rptr;
            }
        }
        return -1;
    }



};
