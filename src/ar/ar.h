#ifndef _AR_H_
#define _AR_H_

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

typedef struct ar_t{
    char *buf;
    size_t buf_len;
    size_t rptr;
    int used;
}ar_t;

#endif
