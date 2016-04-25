#include "..h"
namespace conf {

ItemPoolConf::ItemPoolConf() {
   clear();
}

ItemPoolConf::~ItemPoolConf() {
   clear();
}

int ItemPoolConf::load(lua_State* L) {
   int top = lua_gettop(L);
   lua_getglobal(L, "conf");
   if(lua_isnil(L, -1)) {
       LOG_ERROR("null wrong");
       lua_pop(L, lua_gettop(L) - top);
       return 1;
   }
   lua_pushstring(L, "ItemPoolConf");
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

int ItemPoolConf::_load(lua_State* L) {
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
   lua_pushstring(L, "itemmap");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       lua_pushnil(L);  /* first key */
       while (lua_next(L, -2) != 0) {
           if (lua_isnumber(L, -2) && lua_istable(L, -1)) {
               int index = (int)lua_tointeger(L, -2);
               ItemConf *value = new ItemConf();
               this->itemmap[index] = value;
               value->_load(L);
           }
           lua_pop(L, 1);
       }
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
   lua_pushstring(L, "name");
   lua_gettable(L, -2);
   if(!lua_isnil(L, -1)) {
       this->name = (char*)lua_tostring(L, -1);
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

void ItemPoolConf::print() {
   printf("{\n");
   printf("_class = %s\n", this->_class.data());
   {
       std::map<int, ItemConf*>::iterator iter = this->itemmap.begin();
       for(;iter != this->itemmap.end(); ++iter){
           printf("itemmap[%d] =\n", iter->first);
           ItemConf *value = iter->second;
           value->print();
       }
   }
   printf("id = %d\n", this->id);
   printf("name = %s\n", this->name.data());
   printf("value = %f\n", this->value);
   printf("}\n");
}

void ItemPoolConf::clear() {
   {
       std::map<int, ItemConf*>::iterator iter = this->itemmap.begin();
       for(;iter != this->itemmap.end(); ++iter){
           ItemConf *value = iter->second;
           delete value;
       }
       this->itemmap.clear();
   }
   this->id = 0;
   this->value = 0;
}

int ItemPoolConf::reload(lua_State* L) {
   clear();
   return load(L);
}

ItemPoolConf::ItemConf::ItemConf() {
   clear();
}

ItemPoolConf::ItemConf::~ItemConf() {
   clear();
}

int ItemPoolConf::ItemConf::load(lua_State* L) {
   int top = lua_gettop(L);
   lua_getglobal(L, "conf");
   if(lua_isnil(L, -1)) {
       LOG_ERROR("null wrong");
       lua_pop(L, lua_gettop(L) - top);
       return 1;
   }
   lua_pushstring(L, "ItemConf");
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

int ItemPoolConf::ItemConf::_load(lua_State* L) {
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

void ItemPoolConf::ItemConf::print() {
   printf("{\n");
   printf("_class = %s\n", this->_class.data());
   printf("itemid = %d\n", this->itemid);
   printf("name = %s\n", this->name.data());
   printf("}\n");
}

void ItemPoolConf::ItemConf::clear() {
   this->itemid = 0;
}

int ItemPoolConf::ItemConf::reload(lua_State* L) {
   clear();
   return load(L);
}


};
