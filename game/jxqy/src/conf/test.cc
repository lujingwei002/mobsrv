#include "item_pool_conf.h"
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include <stdio.h>

int main ()
{
	lua_State* L = lua_open();
	luaopen_base(L);
	luaL_dofile(L,"test.lua");
    conf::item_pool_conf item_pool;
    item_pool.load(L);
    printf("id: %d\n", item_pool.id);
    printf("vlaue: %f\n", item_pool.value);
    printf("name: %s\n", item_pool.name.data());
    printf("itemlist size(): %d\n", item_pool.itemlist1.size());
    conf::item_pool_conf::item_conf *item = item_pool.itemlist1[1];
    printf("name: %s\n", item->name.data());
    printf("_class: %s\n", item->_class.data());
	lua_close(L);
    printf("test\n");
	return 0;
}

