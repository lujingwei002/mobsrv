#ifndef __LSTRPORT_H__
#define __LSTRPORT_H__

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
int luaopen_strport(lua_State *L);

#endif
