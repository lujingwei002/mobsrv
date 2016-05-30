
#include "srvlib.h"

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


int luaopen_srvlib(lua_State *L)
{
    luaopen_ae(L);
    luaopen_recvbuf(L);
    luaopen_sendbuf(L);
    luaopen_timer(L);
    luaopen_port(L);
    luaopen_ar(L);
    luaopen_bit(L);
    luaopen_date(L);
    luaopen_file(L);
    luaopen_json(L);
    luaopen_log(L);
    luaopen_mysql(L);
    luaopen_redis(L);
    luaopen_cstring(L);
    luaopen_system(L);
    luaopen_strport(L);
	return 1;
}

