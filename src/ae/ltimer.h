#ifndef _TIMER_H_
#define _TIMER_H_

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int luaopen_timer(lua_State *L);

#endif
