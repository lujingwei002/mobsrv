#ifndef _LPORT_H_
#define _LPORT_H_


extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
int luaopen_port(lua_State *L);

#endif

