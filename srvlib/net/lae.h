#ifndef _LAE_H_
#define _LAE_H_

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int luaopen_ae(lua_State *L);

#endif
