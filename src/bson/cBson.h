#ifndef _C_BSON_H
#define _C_BSON_H

#include "bson.h"
extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}



bson* cBSON_CreateNull();
bson* cBSON_CreateBool(int b);
bson* cBSON_CreateNumber(double num);
bson* cBSON_CreateString(const char* string);
int cBSON_AppendBool(lua_State *L,bson *b,const char *key);
int cBSON_AppendNumber(lua_State *L,bson *b,const char *key);
int cBSON_AppendString(lua_State *L,bson *b,const char *key);
#endif
