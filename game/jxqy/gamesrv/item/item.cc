#include "stdafx.h"

namespace Item {

Conf::ItemPoolConf item_pool_conf;

void print_conf() {
    item_pool_conf.print();
}

int reload_conf(lua_State* L) {
    item_pool_conf.reload(L);
    return 0;
}

int load_conf(lua_State* L) {
    item_pool_conf.load(L);
    return 0;
}

int add_item(dbproto::PlayerData* playerdata, int itemid, int itemcount) {
    LOG_LOG("add item id(%d) count(%d)", itemid, itemcount);
    dbproto::ItemData* itemdata = playerdata->mutable_itemdata();
    dbproto::Item *item = itemdata->add_items();
    item->set_id(itemid);
    item->set_count(itemcount);
    return 0;
}

};
