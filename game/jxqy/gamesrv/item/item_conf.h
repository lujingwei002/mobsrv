#ifndef _ITEMPOOLCONF_H_
#define _ITEMPOOLCONF_H_
//此文件自动生成，请不要修改!!!!!!!!!!!!!!!!!!!!!
#include "stdafx.h"
namespace Conf {


/********ItemPoolConf开始*************/
class ItemPoolConf {
public:
   ItemPoolConf();
   ~ItemPoolConf();
   void clear();
   int load(lua_State* L);
   int _load(lua_State* L);
   int reload(lua_State* L);
   void print();
   std::string _class;

/********ItemConf开始*************/
class ItemConf {
public:
   ItemConf();
   ~ItemConf();
   void clear();
   int load(lua_State* L);
   int _load(lua_State* L);
   int reload(lua_State* L);
   void print();
   std::string _class;
   int itemid;
   std::string name;
};
/********ItemConf结束*************/

   std::map<int, ItemConf*> itemmap;
   int id;
   std::string name;
   double value;
};
/********ItemPoolConf结束*************/


};
#endif
