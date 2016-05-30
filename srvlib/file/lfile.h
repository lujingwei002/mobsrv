#ifndef __LFILE_H__
#define __LFILE_H__ 

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int luaopen_file(lua_State *L);

#endif
