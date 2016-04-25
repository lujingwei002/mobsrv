#ifndef _ITEM_POOL_CONF_H_
#define _ITEM_POOL_CONF_H_
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include "log.h"
#include <string>
#include <map>
namespace conf {


/********item_pool_conf开始*************/
class item_pool_conf {
public:
   item_pool_conf();
   ~item_pool_conf();
   void clear();
   int load(lua_State* L);
   int _load(lua_State* L);
   int reload(lua_State* L);
   std::string _class;
   std::string name;
   int id;

/********item_conf开始*************/
class item_conf {
public:
   item_conf();
   ~item_conf();
   void clear();
   int load(lua_State* L);
   int _load(lua_State* L);
   int reload(lua_State* L);
   std::string _class;
   int itemid;
   std::string name;
};
/********item_conf结束*************/

   std::map<int, item_conf*> itemlist1;
   double value;
};
/********item_pool_conf结束*************/


/********achieve_pool_conf开始*************/
class achieve_pool_conf {
public:
   achieve_pool_conf();
   ~achieve_pool_conf();
   void clear();
   int load(lua_State* L);
   int _load(lua_State* L);
   int reload(lua_State* L);
   int id;
   std::string _class;
   std::string name;
};
/********achieve_pool_conf结束*************/


};
#endif
