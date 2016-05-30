#ifndef _LDATE_H_
#define _LDATE_H_

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
int luaopen_date(lua_State *L);

#endif
