#ifndef _BSON_ENCODE_H_
#define _BSON_ENCODE_H_
#include "bson.h"

extern "C"{

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}



int bson_regist(lua_State *L);

bson* bson_encode(lua_State *L);
int bson_decode(lua_State* L, const bson *b_lua);


#endif
