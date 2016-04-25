

#include "stdafx.h"


extern "C" {

int luaopen_libsrv(lua_State *L)
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
    luaopen_socket(L);
    luaopen_srvmain(L);
    luaopen_cstring(L);
    luaopen_system(L);
    luaopen_strport(L);
	return 1;
}

}
