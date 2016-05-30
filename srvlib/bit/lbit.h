#ifndef _LBIT_H_
#define _LBIT_H_

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int luaopen_bit(lua_State *L);

#endif
