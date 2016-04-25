#include <netdb.h>
#include <execinfo.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

static int lbitand(lua_State *L){
    int n1 = (int)lua_tointeger(L, 1);
    int n2 = (int)lua_tointeger(L, 2);
    int result = n1 & n2;
    lua_pushinteger(L, result);
    return 1;
}

static int lbitnot(lua_State *L){
    int n1 = (int)lua_tointeger(L, 1);
    int result = ~n1;
    lua_pushinteger(L, result);
    return 1;
}
static int lbitor(lua_State *L){
    int n1 = (int)lua_tointeger(L, 1);
    int n2 = (int)lua_tointeger(L, 2);
    int result = n1 | n2;
    lua_pushinteger(L, result);
    return 1;
}

static luaL_Reg lua_lib[] ={
    {"bitor", lbitor},
    {"bitand", lbitand},
    {"bitnot", lbitnot},
    {NULL, NULL}
};

extern "C" {
int luaopen_bitpatch(lua_State *L){
	luaL_register(L, "bit", lua_lib);
	return 1;
}
}
