#include "item_pool_conf.h"
namespace conf {

item_pool_conf::item_pool_conf() {
   clear();
}

item_pool_conf::~item_pool_conf() {
   clear();
}

int item_pool_conf::load(lua_State* L) {
   int top = lua_gettop(L);
   lua_getglobal(L, "conf");
   if(lua_isnil(L, -1)) {
       LOG_ERROR("null wrong");
       lua_pop(L, lua_gettop(L) - top);
       return 1;
   }
   lua_pushstring(L, "item_pool_conf");
   lua_gettable(L, -2);
   if(lua_isnil(L, -1)) {
       LOG_ERROR("null wrong");
       lua_pop(L, lua_gettop(L) - top);
       return 1;
   }
   int result =  _load(L);
   lua_pop(L, lua_gettop(L) - top);
   return result;
}

int item_pool_conf::_load(lua_State* L) {
   int top = lua_gettop(L);
{
   lua_pushstring(L, "_class");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->_class = (char*)lua_tostring(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
{
   lua_pushstring(L, "name");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->name = (char*)lua_tostring(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
{
   lua_pushstring(L, "id");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->id = (int)lua_tointeger(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
{
   lua_pushstring(L, "itemlist1");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       lua_pushnil(L);  /* first key */
       while (lua_next(L, -2) != 0) {
           if (lua_isnumber(L, -2) && lua_istable(L, -1)) {
               int index = (int)lua_tointeger(L, -2);
               item_conf *value = new item_conf();
               this->itemlist1[index] = value;
               value->_load(L);
           }
           lua_pop(L, 1);
       }
   }
   lua_remove(L, -1);//弹出value
}
{
   lua_pushstring(L, "value");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->value = (double)lua_tonumber(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
   lua_pop(L, lua_gettop(L) - top);
   return 0;
}

void item_pool_conf::clear() {
   this->id = 0;
   {
       std::map<int, item_conf*>::iterator iter = this->itemlist1.begin();
       for(;iter != this->itemlist1.end(); ++iter){
           item_conf *value = iter->second;
           delete value;
       }
       this->itemlist1.clear();
   }
   this->value = 0;
}

int item_pool_conf::reload(lua_State* L) {
   clear();
   return load(L);
}

item_pool_conf::item_conf::item_conf() {
   clear();
}

item_pool_conf::item_conf::~item_conf() {
   clear();
}

int item_pool_conf::item_conf::load(lua_State* L) {
   int top = lua_gettop(L);
   lua_getglobal(L, "conf");
   if(lua_isnil(L, -1)) {
       LOG_ERROR("null wrong");
       lua_pop(L, lua_gettop(L) - top);
       return 1;
   }
   lua_pushstring(L, "item_conf");
   lua_gettable(L, -2);
   if(lua_isnil(L, -1)) {
       LOG_ERROR("null wrong");
       lua_pop(L, lua_gettop(L) - top);
       return 1;
   }
   int result =  _load(L);
   lua_pop(L, lua_gettop(L) - top);
   return result;
}

int item_pool_conf::item_conf::_load(lua_State* L) {
   int top = lua_gettop(L);
{
   lua_pushstring(L, "_class");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->_class = (char*)lua_tostring(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
{
   lua_pushstring(L, "itemid");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->itemid = (int)lua_tointeger(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
{
   lua_pushstring(L, "name");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->name = (char*)lua_tostring(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
   lua_pop(L, lua_gettop(L) - top);
   return 0;
}

void item_pool_conf::item_conf::clear() {
   this->itemid = 0;
}

int item_pool_conf::item_conf::reload(lua_State* L) {
   clear();
   return load(L);
}

achieve_pool_conf::achieve_pool_conf() {
   clear();
}

achieve_pool_conf::~achieve_pool_conf() {
   clear();
}

int achieve_pool_conf::load(lua_State* L) {
   int top = lua_gettop(L);
   lua_getglobal(L, "conf");
   if(lua_isnil(L, -1)) {
       LOG_ERROR("null wrong");
       lua_pop(L, lua_gettop(L) - top);
       return 1;
   }
   lua_pushstring(L, "achieve_pool_conf");
   lua_gettable(L, -2);
   if(lua_isnil(L, -1)) {
       LOG_ERROR("null wrong");
       lua_pop(L, lua_gettop(L) - top);
       return 1;
   }
   int result =  _load(L);
   lua_pop(L, lua_gettop(L) - top);
   return result;
}

int achieve_pool_conf::_load(lua_State* L) {
   int top = lua_gettop(L);
{
   lua_pushstring(L, "id");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->id = (int)lua_tointeger(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
{
   lua_pushstring(L, "_class");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->_class = (char*)lua_tostring(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
{
   lua_pushstring(L, "name");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->name = (char*)lua_tostring(L, -1);
   }
   lua_remove(L, -1);//弹出value
}
   lua_pop(L, lua_gettop(L) - top);
   return 0;
}

void achieve_pool_conf::clear() {
   this->id = 0;
}

int achieve_pool_conf::reload(lua_State* L) {
   clear();
   return load(L);
}


};
