/*
** Lua binding: gatesrv
** Generated automatically by tolua++-1.0.92 on Mon Dec 28 10:43:10 2015.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_gatesrv_open (lua_State* tolua_S);

#include "gatesrv.h"
#include "test/interface.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"account::LOGIN");
}

/* function: Test::test */
#ifndef TOLUA_DISABLE_tolua_gatesrv_Test_test00
static int tolua_gatesrv_Test_test00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int uid = ((int)  tolua_tonumber(tolua_S,1,0));
  account::LOGIN* msg = ((account::LOGIN*)  tolua_tousertype(tolua_S,2,0));
  {
   int tolua_ret = (int)  Test::test(uid,msg);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'test'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_gatesrv_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"Gatesrv",0);
  tolua_beginmodule(tolua_S,"Gatesrv");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Test",0);
  tolua_beginmodule(tolua_S,"Test");
   tolua_function(tolua_S,"test",tolua_gatesrv_Test_test00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 extern "C"{
 TOLUA_API int luaopen_gatesrv (lua_State* tolua_S) {
 return tolua_gatesrv_open(tolua_S);
};
}
#endif

