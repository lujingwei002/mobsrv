//tolua_begin
#include "stdafx.h"
namespace Item {
    int load_conf(lua_State* L);
    int reload_conf(lua_State* L);
    void print_conf();
    int add_item(dbproto::PlayerData* playerdata, int itemid, int itemcount);
};
//tolua_end
