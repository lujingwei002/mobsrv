#ifndef _LAR_H_
#define _LAR_H_

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int luaopen_ar(lua_State *L);

#endif
