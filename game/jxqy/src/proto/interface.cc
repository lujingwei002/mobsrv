/*
** Lua binding: proto
** Generated automatically by tolua++-1.0.92 on Mon Dec 28 10:31:53 2015.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_proto_open (lua_State* tolua_S);

#include "proto.h"
using namespace std;
using namespace google::protobuf;
#define TOLUA_RELEASE

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_regist__CREATE (lua_State* tolua_S)
{
 regist::CREATE* self = (regist::CREATE*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_login__DISCONNECT (lua_State* tolua_S)
{
 login::DISCONNECT* self = (login::DISCONNECT*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_sys__PING (lua_State* tolua_S)
{
 sys::PING* self = (sys::PING*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_login__LOGIN (lua_State* tolua_S)
{
 login::LOGIN* self = (login::LOGIN*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_account__REGIST (lua_State* tolua_S)
{
 account::REGIST* self = (account::REGIST*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_sys__TEST (lua_State* tolua_S)
{
 sys::TEST* self = (sys::TEST*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_account__LOGIN (lua_State* tolua_S)
{
 account::LOGIN* self = (account::LOGIN*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_login__ENTER (lua_State* tolua_S)
{
 login::ENTER* self = (login::ENTER*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_sys__GM (lua_State* tolua_S)
{
 sys::GM* self = (sys::GM*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_sdk91__LOGIN (lua_State* tolua_S)
{
 sdk91::LOGIN* self = (sdk91::LOGIN*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_login__PING (lua_State* tolua_S)
{
 login::PING* self = (login::PING*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"regist::CREATE");
 tolua_usertype(tolua_S,"login::DISCONNECT");
 tolua_usertype(tolua_S,"sys::PING");
 tolua_usertype(tolua_S,"login::LOGIN");
 tolua_usertype(tolua_S,"account::REGIST");
 tolua_usertype(tolua_S,"sys::TEST");
 tolua_usertype(tolua_S,"account::LOGIN");
 tolua_usertype(tolua_S,"login::ENTER");
 tolua_usertype(tolua_S,"sys::GM");
 tolua_usertype(tolua_S,"sdk91::LOGIN");
 tolua_usertype(tolua_S,"login::PING");
}

/* method: new of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_new00
static int tolua_proto_account_LOGIN_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   account::LOGIN* tolua_ret = (account::LOGIN*)  new account::LOGIN();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"account::LOGIN");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_new00_local
static int tolua_proto_account_LOGIN_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   account::LOGIN* tolua_ret = (account::LOGIN*)  new account::LOGIN();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"account::LOGIN");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_delete00
static int tolua_proto_account_LOGIN_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_clear00
static int tolua_proto_account_LOGIN_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_debug_string00
static int tolua_proto_account_LOGIN_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_msgname00
static int tolua_proto_account_LOGIN_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_bytesize00
static int tolua_proto_account_LOGIN_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account_LOGIN_tostring of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_tostring00
static int tolua_proto_account_LOGIN_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account_LOGIN_tostring'",NULL);
#endif
  {
return account_LOGIN_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account_LOGIN_parse_from_string of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_parse_from_string00
static int tolua_proto_account_LOGIN_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account_LOGIN_parse_from_string'",NULL);
#endif
  {
return account_LOGIN_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account_LOGIN_parse_from_buf of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_parse_from_buf00
static int tolua_proto_account_LOGIN_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account_LOGIN_parse_from_buf'",NULL);
#endif
  {
return account_LOGIN_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account_LOGIN_serialize of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_account_LOGIN_serialize00
static int tolua_proto_account_LOGIN_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account_LOGIN_serialize'",NULL);
#endif
  {
return account_LOGIN_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: password of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_account__LOGIN_password
static int tolua_get_account__LOGIN_password(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'password'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->password());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: password of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_account__LOGIN_password
static int tolua_set_account__LOGIN_password(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'password'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_password(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uid of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_account__LOGIN_uid
static int tolua_get_account__LOGIN_uid(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->uid());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uid of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_account__LOGIN_uid
static int tolua_set_account__LOGIN_uid(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_uid(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: time of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_account__LOGIN_time
static int tolua_get_account__LOGIN_time(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'time'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->time());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: time of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_account__LOGIN_time
static int tolua_set_account__LOGIN_time(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'time'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_time(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: err of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_account__LOGIN_err
static int tolua_get_account__LOGIN_err(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->err());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: err of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_account__LOGIN_err
static int tolua_set_account__LOGIN_err(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_err(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: params of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_account__LOGIN_params
static int tolua_get_account__LOGIN_params(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'params'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->params());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: params of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_account__LOGIN_params
static int tolua_set_account__LOGIN_params(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'params'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_params(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: email of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_account__LOGIN_email
static int tolua_get_account__LOGIN_email(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'email'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->email());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: email of class  account::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_account__LOGIN_email
static int tolua_set_account__LOGIN_email(lua_State* tolua_S)
{
  account::LOGIN* self = (account::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'email'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_email(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_new00
static int tolua_proto_sys_TEST_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   sys::TEST* tolua_ret = (sys::TEST*)  new sys::TEST();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"sys::TEST");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_new00_local
static int tolua_proto_sys_TEST_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   sys::TEST* tolua_ret = (sys::TEST*)  new sys::TEST();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"sys::TEST");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_delete00
static int tolua_proto_sys_TEST_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_clear00
static int tolua_proto_sys_TEST_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_debug_string00
static int tolua_proto_sys_TEST_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_msgname00
static int tolua_proto_sys_TEST_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_bytesize00
static int tolua_proto_sys_TEST_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_TEST_tostring of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_tostring00
static int tolua_proto_sys_TEST_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_TEST_tostring'",NULL);
#endif
  {
return sys_TEST_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_TEST_parse_from_string of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_parse_from_string00
static int tolua_proto_sys_TEST_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_TEST_parse_from_string'",NULL);
#endif
  {
return sys_TEST_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_TEST_parse_from_buf of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_parse_from_buf00
static int tolua_proto_sys_TEST_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_TEST_parse_from_buf'",NULL);
#endif
  {
return sys_TEST_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_TEST_serialize of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_proto_sys_TEST_serialize00
static int tolua_proto_sys_TEST_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::TEST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_TEST_serialize'",NULL);
#endif
  {
return sys_TEST_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: str of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_get_sys__TEST_str
static int tolua_get_sys__TEST_str(lua_State* tolua_S)
{
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'str'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->str());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: str of class  sys::TEST */
#ifndef TOLUA_DISABLE_tolua_set_sys__TEST_str
static int tolua_set_sys__TEST_str(lua_State* tolua_S)
{
  sys::TEST* self = (sys::TEST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'str'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_str(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_new00
static int tolua_proto_login_LOGIN_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   login::LOGIN* tolua_ret = (login::LOGIN*)  new login::LOGIN();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"login::LOGIN");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_new00_local
static int tolua_proto_login_LOGIN_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   login::LOGIN* tolua_ret = (login::LOGIN*)  new login::LOGIN();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"login::LOGIN");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_delete00
static int tolua_proto_login_LOGIN_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_clear00
static int tolua_proto_login_LOGIN_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_debug_string00
static int tolua_proto_login_LOGIN_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_msgname00
static int tolua_proto_login_LOGIN_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_bytesize00
static int tolua_proto_login_LOGIN_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_LOGIN_tostring of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_tostring00
static int tolua_proto_login_LOGIN_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_LOGIN_tostring'",NULL);
#endif
  {
return login_LOGIN_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_LOGIN_parse_from_string of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_parse_from_string00
static int tolua_proto_login_LOGIN_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_LOGIN_parse_from_string'",NULL);
#endif
  {
return login_LOGIN_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_LOGIN_parse_from_buf of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_parse_from_buf00
static int tolua_proto_login_LOGIN_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_LOGIN_parse_from_buf'",NULL);
#endif
  {
return login_LOGIN_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_LOGIN_serialize of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_login_LOGIN_serialize00
static int tolua_proto_login_LOGIN_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_LOGIN_serialize'",NULL);
#endif
  {
return login_LOGIN_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: str of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_login__LOGIN_str
static int tolua_get_login__LOGIN_str(lua_State* tolua_S)
{
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'str'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->str());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: str of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_login__LOGIN_str
static int tolua_set_login__LOGIN_str(lua_State* tolua_S)
{
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'str'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_str(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uid of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_login__LOGIN_uid
static int tolua_get_login__LOGIN_uid(lua_State* tolua_S)
{
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->uid());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uid of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_login__LOGIN_uid
static int tolua_set_login__LOGIN_uid(lua_State* tolua_S)
{
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_uid(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: err of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_login__LOGIN_err
static int tolua_get_login__LOGIN_err(lua_State* tolua_S)
{
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->err());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: err of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_login__LOGIN_err
static int tolua_set_login__LOGIN_err(lua_State* tolua_S)
{
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_err(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: params of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_login__LOGIN_params
static int tolua_get_login__LOGIN_params(lua_State* tolua_S)
{
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'params'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->params());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: params of class  login::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_login__LOGIN_params
static int tolua_set_login__LOGIN_params(lua_State* tolua_S)
{
  login::LOGIN* self = (login::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'params'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_params(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_new00
static int tolua_proto_sys_GM_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   sys::GM* tolua_ret = (sys::GM*)  new sys::GM();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"sys::GM");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_new00_local
static int tolua_proto_sys_GM_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   sys::GM* tolua_ret = (sys::GM*)  new sys::GM();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"sys::GM");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_delete00
static int tolua_proto_sys_GM_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_clear00
static int tolua_proto_sys_GM_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_debug_string00
static int tolua_proto_sys_GM_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_msgname00
static int tolua_proto_sys_GM_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_bytesize00
static int tolua_proto_sys_GM_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_GM_tostring of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_tostring00
static int tolua_proto_sys_GM_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_GM_tostring'",NULL);
#endif
  {
return sys_GM_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_GM_parse_from_string of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_parse_from_string00
static int tolua_proto_sys_GM_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_GM_parse_from_string'",NULL);
#endif
  {
return sys_GM_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_GM_parse_from_buf of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_parse_from_buf00
static int tolua_proto_sys_GM_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_GM_parse_from_buf'",NULL);
#endif
  {
return sys_GM_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_GM_serialize of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_proto_sys_GM_serialize00
static int tolua_proto_sys_GM_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::GM",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_GM_serialize'",NULL);
#endif
  {
return sys_GM_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: str of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_get_sys__GM_str
static int tolua_get_sys__GM_str(lua_State* tolua_S)
{
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'str'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->str());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: str of class  sys::GM */
#ifndef TOLUA_DISABLE_tolua_set_sys__GM_str
static int tolua_set_sys__GM_str(lua_State* tolua_S)
{
  sys::GM* self = (sys::GM*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'str'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_str(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_new00
static int tolua_proto_login_PING_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   login::PING* tolua_ret = (login::PING*)  new login::PING();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"login::PING");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_new00_local
static int tolua_proto_login_PING_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   login::PING* tolua_ret = (login::PING*)  new login::PING();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"login::PING");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_delete00
static int tolua_proto_login_PING_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_clear00
static int tolua_proto_login_PING_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_debug_string00
static int tolua_proto_login_PING_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_msgname00
static int tolua_proto_login_PING_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_bytesize00
static int tolua_proto_login_PING_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_PING_tostring of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_tostring00
static int tolua_proto_login_PING_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_PING_tostring'",NULL);
#endif
  {
return login_PING_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_PING_parse_from_string of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_parse_from_string00
static int tolua_proto_login_PING_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_PING_parse_from_string'",NULL);
#endif
  {
return login_PING_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_PING_parse_from_buf of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_parse_from_buf00
static int tolua_proto_login_PING_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_PING_parse_from_buf'",NULL);
#endif
  {
return login_PING_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_PING_serialize of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_proto_login_PING_serialize00
static int tolua_proto_login_PING_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_PING_serialize'",NULL);
#endif
  {
return login_PING_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: st of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_get_login__PING_st
static int tolua_get_login__PING_st(lua_State* tolua_S)
{
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'st'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->st());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: st of class  login::PING */
#ifndef TOLUA_DISABLE_tolua_set_login__PING_st
static int tolua_set_login__PING_st(lua_State* tolua_S)
{
  login::PING* self = (login::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'st'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_st(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_new00
static int tolua_proto_sys_PING_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   sys::PING* tolua_ret = (sys::PING*)  new sys::PING();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"sys::PING");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_new00_local
static int tolua_proto_sys_PING_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   sys::PING* tolua_ret = (sys::PING*)  new sys::PING();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"sys::PING");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_delete00
static int tolua_proto_sys_PING_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_clear00
static int tolua_proto_sys_PING_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_debug_string00
static int tolua_proto_sys_PING_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_msgname00
static int tolua_proto_sys_PING_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_bytesize00
static int tolua_proto_sys_PING_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_PING_tostring of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_tostring00
static int tolua_proto_sys_PING_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_PING_tostring'",NULL);
#endif
  {
return sys_PING_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_PING_parse_from_string of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_parse_from_string00
static int tolua_proto_sys_PING_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_PING_parse_from_string'",NULL);
#endif
  {
return sys_PING_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_PING_parse_from_buf of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_parse_from_buf00
static int tolua_proto_sys_PING_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_PING_parse_from_buf'",NULL);
#endif
  {
return sys_PING_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sys_PING_serialize of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_proto_sys_PING_serialize00
static int tolua_proto_sys_PING_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sys::PING",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sys_PING_serialize'",NULL);
#endif
  {
return sys_PING_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: st of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_get_sys__PING_st
static int tolua_get_sys__PING_st(lua_State* tolua_S)
{
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'st'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->st());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: st of class  sys::PING */
#ifndef TOLUA_DISABLE_tolua_set_sys__PING_st
static int tolua_set_sys__PING_st(lua_State* tolua_S)
{
  sys::PING* self = (sys::PING*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'st'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_st(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_new00
static int tolua_proto_login_ENTER_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   login::ENTER* tolua_ret = (login::ENTER*)  new login::ENTER();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"login::ENTER");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_new00_local
static int tolua_proto_login_ENTER_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   login::ENTER* tolua_ret = (login::ENTER*)  new login::ENTER();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"login::ENTER");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_delete00
static int tolua_proto_login_ENTER_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_clear00
static int tolua_proto_login_ENTER_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_debug_string00
static int tolua_proto_login_ENTER_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_msgname00
static int tolua_proto_login_ENTER_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_bytesize00
static int tolua_proto_login_ENTER_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_ENTER_tostring of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_tostring00
static int tolua_proto_login_ENTER_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_ENTER_tostring'",NULL);
#endif
  {
return login_ENTER_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_ENTER_parse_from_string of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_parse_from_string00
static int tolua_proto_login_ENTER_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_ENTER_parse_from_string'",NULL);
#endif
  {
return login_ENTER_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_ENTER_parse_from_buf of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_parse_from_buf00
static int tolua_proto_login_ENTER_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_ENTER_parse_from_buf'",NULL);
#endif
  {
return login_ENTER_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_ENTER_serialize of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_proto_login_ENTER_serialize00
static int tolua_proto_login_ENTER_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::ENTER",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_ENTER_serialize'",NULL);
#endif
  {
return login_ENTER_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: err of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_get_login__ENTER_err
static int tolua_get_login__ENTER_err(lua_State* tolua_S)
{
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->err());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: err of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_set_login__ENTER_err
static int tolua_set_login__ENTER_err(lua_State* tolua_S)
{
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_err(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: srvid of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_get_login__ENTER_srvid
static int tolua_get_login__ENTER_srvid(lua_State* tolua_S)
{
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'srvid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->srvid());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: srvid of class  login::ENTER */
#ifndef TOLUA_DISABLE_tolua_set_login__ENTER_srvid
static int tolua_set_login__ENTER_srvid(lua_State* tolua_S)
{
  login::ENTER* self = (login::ENTER*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'srvid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_srvid(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_new00
static int tolua_proto_login_DISCONNECT_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   login::DISCONNECT* tolua_ret = (login::DISCONNECT*)  new login::DISCONNECT();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"login::DISCONNECT");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_new00_local
static int tolua_proto_login_DISCONNECT_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   login::DISCONNECT* tolua_ret = (login::DISCONNECT*)  new login::DISCONNECT();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"login::DISCONNECT");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_delete00
static int tolua_proto_login_DISCONNECT_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_clear00
static int tolua_proto_login_DISCONNECT_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_debug_string00
static int tolua_proto_login_DISCONNECT_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_msgname00
static int tolua_proto_login_DISCONNECT_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_bytesize00
static int tolua_proto_login_DISCONNECT_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_DISCONNECT_tostring of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_tostring00
static int tolua_proto_login_DISCONNECT_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_DISCONNECT_tostring'",NULL);
#endif
  {
return login_DISCONNECT_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_DISCONNECT_parse_from_string of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_parse_from_string00
static int tolua_proto_login_DISCONNECT_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_DISCONNECT_parse_from_string'",NULL);
#endif
  {
return login_DISCONNECT_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_DISCONNECT_parse_from_buf of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_parse_from_buf00
static int tolua_proto_login_DISCONNECT_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_DISCONNECT_parse_from_buf'",NULL);
#endif
  {
return login_DISCONNECT_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: login_DISCONNECT_serialize of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_proto_login_DISCONNECT_serialize00
static int tolua_proto_login_DISCONNECT_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"login::DISCONNECT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'login_DISCONNECT_serialize'",NULL);
#endif
  {
return login_DISCONNECT_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: remain_time of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_get_login__DISCONNECT_remain_time
static int tolua_get_login__DISCONNECT_remain_time(lua_State* tolua_S)
{
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'remain_time'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->remain_time());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: remain_time of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_set_login__DISCONNECT_remain_time
static int tolua_set_login__DISCONNECT_remain_time(lua_State* tolua_S)
{
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'remain_time'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_remain_time(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: err of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_get_login__DISCONNECT_err
static int tolua_get_login__DISCONNECT_err(lua_State* tolua_S)
{
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->err());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: err of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_set_login__DISCONNECT_err
static int tolua_set_login__DISCONNECT_err(lua_State* tolua_S)
{
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_err(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: reason of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_get_login__DISCONNECT_reason
static int tolua_get_login__DISCONNECT_reason(lua_State* tolua_S)
{
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reason'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->reason());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: reason of class  login::DISCONNECT */
#ifndef TOLUA_DISABLE_tolua_set_login__DISCONNECT_reason
static int tolua_set_login__DISCONNECT_reason(lua_State* tolua_S)
{
  login::DISCONNECT* self = (login::DISCONNECT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reason'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_reason(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_new00
static int tolua_proto_account_REGIST_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   account::REGIST* tolua_ret = (account::REGIST*)  new account::REGIST();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"account::REGIST");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_new00_local
static int tolua_proto_account_REGIST_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   account::REGIST* tolua_ret = (account::REGIST*)  new account::REGIST();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"account::REGIST");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_delete00
static int tolua_proto_account_REGIST_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_clear00
static int tolua_proto_account_REGIST_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_debug_string00
static int tolua_proto_account_REGIST_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_msgname00
static int tolua_proto_account_REGIST_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_bytesize00
static int tolua_proto_account_REGIST_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account_REGIST_tostring of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_tostring00
static int tolua_proto_account_REGIST_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account_REGIST_tostring'",NULL);
#endif
  {
return account_REGIST_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account_REGIST_parse_from_string of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_parse_from_string00
static int tolua_proto_account_REGIST_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account_REGIST_parse_from_string'",NULL);
#endif
  {
return account_REGIST_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account_REGIST_parse_from_buf of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_parse_from_buf00
static int tolua_proto_account_REGIST_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account_REGIST_parse_from_buf'",NULL);
#endif
  {
return account_REGIST_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account_REGIST_serialize of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_proto_account_REGIST_serialize00
static int tolua_proto_account_REGIST_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"account::REGIST",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account_REGIST_serialize'",NULL);
#endif
  {
return account_REGIST_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: password of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_get_account__REGIST_password
static int tolua_get_account__REGIST_password(lua_State* tolua_S)
{
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'password'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->password());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: password of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_set_account__REGIST_password
static int tolua_set_account__REGIST_password(lua_State* tolua_S)
{
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'password'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_password(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: err of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_get_account__REGIST_err
static int tolua_get_account__REGIST_err(lua_State* tolua_S)
{
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->err());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: err of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_set_account__REGIST_err
static int tolua_set_account__REGIST_err(lua_State* tolua_S)
{
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_err(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: email of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_get_account__REGIST_email
static int tolua_get_account__REGIST_email(lua_State* tolua_S)
{
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'email'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->email());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: email of class  account::REGIST */
#ifndef TOLUA_DISABLE_tolua_set_account__REGIST_email
static int tolua_set_account__REGIST_email(lua_State* tolua_S)
{
  account::REGIST* self = (account::REGIST*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'email'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_email(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_new00
static int tolua_proto_regist_CREATE_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   regist::CREATE* tolua_ret = (regist::CREATE*)  new regist::CREATE();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"regist::CREATE");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_new00_local
static int tolua_proto_regist_CREATE_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   regist::CREATE* tolua_ret = (regist::CREATE*)  new regist::CREATE();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"regist::CREATE");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_delete00
static int tolua_proto_regist_CREATE_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_clear00
static int tolua_proto_regist_CREATE_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_debug_string00
static int tolua_proto_regist_CREATE_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_msgname00
static int tolua_proto_regist_CREATE_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_bytesize00
static int tolua_proto_regist_CREATE_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: regist_CREATE_tostring of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_tostring00
static int tolua_proto_regist_CREATE_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'regist_CREATE_tostring'",NULL);
#endif
  {
return regist_CREATE_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: regist_CREATE_parse_from_string of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_parse_from_string00
static int tolua_proto_regist_CREATE_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'regist_CREATE_parse_from_string'",NULL);
#endif
  {
return regist_CREATE_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: regist_CREATE_parse_from_buf of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_parse_from_buf00
static int tolua_proto_regist_CREATE_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'regist_CREATE_parse_from_buf'",NULL);
#endif
  {
return regist_CREATE_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: regist_CREATE_serialize of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_proto_regist_CREATE_serialize00
static int tolua_proto_regist_CREATE_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"regist::CREATE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'regist_CREATE_serialize'",NULL);
#endif
  {
return regist_CREATE_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: platform_id of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_get_regist__CREATE_platform_id
static int tolua_get_regist__CREATE_platform_id(lua_State* tolua_S)
{
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'platform_id'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->platform_id());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: platform_id of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_set_regist__CREATE_platform_id
static int tolua_set_regist__CREATE_platform_id(lua_State* tolua_S)
{
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'platform_id'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_platform_id(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: err of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_get_regist__CREATE_err
static int tolua_get_regist__CREATE_err(lua_State* tolua_S)
{
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->err());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: err of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_set_regist__CREATE_err
static int tolua_set_regist__CREATE_err(lua_State* tolua_S)
{
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_err(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: role_type of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_get_regist__CREATE_role_type
static int tolua_get_regist__CREATE_role_type(lua_State* tolua_S)
{
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'role_type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->role_type());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: role_type of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_set_regist__CREATE_role_type
static int tolua_set_regist__CREATE_role_type(lua_State* tolua_S)
{
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'role_type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_role_type(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uname of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_get_regist__CREATE_uname
static int tolua_get_regist__CREATE_uname(lua_State* tolua_S)
{
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uname'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->uname());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uname of class  regist::CREATE */
#ifndef TOLUA_DISABLE_tolua_set_regist__CREATE_uname
static int tolua_set_regist__CREATE_uname(lua_State* tolua_S)
{
  regist::CREATE* self = (regist::CREATE*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uname'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_uname(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_new00
static int tolua_proto_sdk91_LOGIN_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   sdk91::LOGIN* tolua_ret = (sdk91::LOGIN*)  new sdk91::LOGIN();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"sdk91::LOGIN");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_new00_local
static int tolua_proto_sdk91_LOGIN_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   sdk91::LOGIN* tolua_ret = (sdk91::LOGIN*)  new sdk91::LOGIN();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"sdk91::LOGIN");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_delete00
static int tolua_proto_sdk91_LOGIN_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_clear00
static int tolua_proto_sdk91_LOGIN_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugString of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_debug_string00
static int tolua_proto_sdk91_LOGIN_debug_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugString'",NULL);
#endif
  {
   string tolua_ret = (string)  self->DebugString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_msgname00
static int tolua_proto_sdk91_LOGIN_msgname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'",NULL);
#endif
  {
   string tolua_ret = (string)  self->GetTypeName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'msgname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_bytesize00
static int tolua_proto_sdk91_LOGIN_bytesize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytesize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sdk91_LOGIN_tostring of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_tostring00
static int tolua_proto_sdk91_LOGIN_tostring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sdk91_LOGIN_tostring'",NULL);
#endif
  {
return sdk91_LOGIN_tostring(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tostring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sdk91_LOGIN_parse_from_string of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_parse_from_string00
static int tolua_proto_sdk91_LOGIN_parse_from_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sdk91_LOGIN_parse_from_string'",NULL);
#endif
  {
return sdk91_LOGIN_parse_from_string(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sdk91_LOGIN_parse_from_buf of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_parse_from_buf00
static int tolua_proto_sdk91_LOGIN_parse_from_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sdk91_LOGIN_parse_from_buf'",NULL);
#endif
  {
return sdk91_LOGIN_parse_from_buf(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parse_from_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sdk91_LOGIN_serialize of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_proto_sdk91_LOGIN_serialize00
static int tolua_proto_sdk91_LOGIN_serialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sdk91::LOGIN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sdk91_LOGIN_serialize'",NULL);
#endif
  {
return sdk91_LOGIN_serialize(self,L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uid of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_sdk91__LOGIN_uid
static int tolua_get_sdk91__LOGIN_uid(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->uid());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uid of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_sdk91__LOGIN_uid
static int tolua_set_sdk91__LOGIN_uid(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_uid(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: time of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_sdk91__LOGIN_time
static int tolua_get_sdk91__LOGIN_time(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'time'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->time());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: time of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_sdk91__LOGIN_time
static int tolua_set_sdk91__LOGIN_time(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'time'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_time(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: session_id of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_sdk91__LOGIN_session_id
static int tolua_get_sdk91__LOGIN_session_id(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'session_id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->session_id());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: session_id of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_sdk91__LOGIN_session_id
static int tolua_set_sdk91__LOGIN_session_id(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'session_id'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_session_id(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: err of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_sdk91__LOGIN_err
static int tolua_get_sdk91__LOGIN_err(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->err());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: err of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_sdk91__LOGIN_err
static int tolua_set_sdk91__LOGIN_err(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'err'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_err(((int32)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: params of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_get_sdk91__LOGIN_params
static int tolua_get_sdk91__LOGIN_params(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'params'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->params());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: params of class  sdk91::LOGIN */
#ifndef TOLUA_DISABLE_tolua_set_sdk91__LOGIN_params
static int tolua_set_sdk91__LOGIN_params(lua_State* tolua_S)
{
  sdk91::LOGIN* self = (sdk91::LOGIN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'params'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->set_params(((string)  tolua_tocppstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_proto_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"account",0);
  tolua_beginmodule(tolua_S,"account");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"LOGIN","account::LOGIN","",tolua_collect_account__LOGIN);
   #else
   tolua_cclass(tolua_S,"LOGIN","account::LOGIN","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"LOGIN");
    tolua_function(tolua_S,"new",tolua_proto_account_LOGIN_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_account_LOGIN_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_account_LOGIN_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_account_LOGIN_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_account_LOGIN_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_account_LOGIN_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_account_LOGIN_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_account_LOGIN_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_account_LOGIN_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_account_LOGIN_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_account_LOGIN_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_account_LOGIN_serialize00);
    tolua_variable(tolua_S,"password",tolua_get_account__LOGIN_password,tolua_set_account__LOGIN_password);
    tolua_variable(tolua_S,"uid",tolua_get_account__LOGIN_uid,tolua_set_account__LOGIN_uid);
    tolua_variable(tolua_S,"time",tolua_get_account__LOGIN_time,tolua_set_account__LOGIN_time);
    tolua_variable(tolua_S,"err",tolua_get_account__LOGIN_err,tolua_set_account__LOGIN_err);
    tolua_variable(tolua_S,"params",tolua_get_account__LOGIN_params,tolua_set_account__LOGIN_params);
    tolua_variable(tolua_S,"email",tolua_get_account__LOGIN_email,tolua_set_account__LOGIN_email);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"sys",0);
  tolua_beginmodule(tolua_S,"sys");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"TEST","sys::TEST","",tolua_collect_sys__TEST);
   #else
   tolua_cclass(tolua_S,"TEST","sys::TEST","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"TEST");
    tolua_function(tolua_S,"new",tolua_proto_sys_TEST_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_sys_TEST_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_sys_TEST_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_sys_TEST_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_sys_TEST_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_sys_TEST_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_sys_TEST_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_sys_TEST_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_sys_TEST_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_sys_TEST_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_sys_TEST_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_sys_TEST_serialize00);
    tolua_variable(tolua_S,"str",tolua_get_sys__TEST_str,tolua_set_sys__TEST_str);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"login",0);
  tolua_beginmodule(tolua_S,"login");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"LOGIN","login::LOGIN","",tolua_collect_login__LOGIN);
   #else
   tolua_cclass(tolua_S,"LOGIN","login::LOGIN","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"LOGIN");
    tolua_function(tolua_S,"new",tolua_proto_login_LOGIN_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_login_LOGIN_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_login_LOGIN_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_login_LOGIN_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_login_LOGIN_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_login_LOGIN_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_login_LOGIN_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_login_LOGIN_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_login_LOGIN_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_login_LOGIN_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_login_LOGIN_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_login_LOGIN_serialize00);
    tolua_variable(tolua_S,"str",tolua_get_login__LOGIN_str,tolua_set_login__LOGIN_str);
    tolua_variable(tolua_S,"uid",tolua_get_login__LOGIN_uid,tolua_set_login__LOGIN_uid);
    tolua_variable(tolua_S,"err",tolua_get_login__LOGIN_err,tolua_set_login__LOGIN_err);
    tolua_variable(tolua_S,"params",tolua_get_login__LOGIN_params,tolua_set_login__LOGIN_params);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"sys",0);
  tolua_beginmodule(tolua_S,"sys");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GM","sys::GM","",tolua_collect_sys__GM);
   #else
   tolua_cclass(tolua_S,"GM","sys::GM","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GM");
    tolua_function(tolua_S,"new",tolua_proto_sys_GM_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_sys_GM_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_sys_GM_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_sys_GM_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_sys_GM_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_sys_GM_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_sys_GM_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_sys_GM_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_sys_GM_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_sys_GM_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_sys_GM_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_sys_GM_serialize00);
    tolua_variable(tolua_S,"str",tolua_get_sys__GM_str,tolua_set_sys__GM_str);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"login",0);
  tolua_beginmodule(tolua_S,"login");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"PING","login::PING","",tolua_collect_login__PING);
   #else
   tolua_cclass(tolua_S,"PING","login::PING","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"PING");
    tolua_function(tolua_S,"new",tolua_proto_login_PING_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_login_PING_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_login_PING_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_login_PING_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_login_PING_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_login_PING_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_login_PING_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_login_PING_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_login_PING_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_login_PING_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_login_PING_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_login_PING_serialize00);
    tolua_variable(tolua_S,"st",tolua_get_login__PING_st,tolua_set_login__PING_st);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"sys",0);
  tolua_beginmodule(tolua_S,"sys");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"PING","sys::PING","",tolua_collect_sys__PING);
   #else
   tolua_cclass(tolua_S,"PING","sys::PING","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"PING");
    tolua_function(tolua_S,"new",tolua_proto_sys_PING_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_sys_PING_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_sys_PING_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_sys_PING_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_sys_PING_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_sys_PING_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_sys_PING_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_sys_PING_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_sys_PING_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_sys_PING_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_sys_PING_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_sys_PING_serialize00);
    tolua_variable(tolua_S,"st",tolua_get_sys__PING_st,tolua_set_sys__PING_st);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"login",0);
  tolua_beginmodule(tolua_S,"login");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ENTER","login::ENTER","",tolua_collect_login__ENTER);
   #else
   tolua_cclass(tolua_S,"ENTER","login::ENTER","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ENTER");
    tolua_function(tolua_S,"new",tolua_proto_login_ENTER_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_login_ENTER_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_login_ENTER_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_login_ENTER_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_login_ENTER_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_login_ENTER_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_login_ENTER_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_login_ENTER_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_login_ENTER_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_login_ENTER_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_login_ENTER_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_login_ENTER_serialize00);
    tolua_variable(tolua_S,"err",tolua_get_login__ENTER_err,tolua_set_login__ENTER_err);
    tolua_variable(tolua_S,"srvid",tolua_get_login__ENTER_srvid,tolua_set_login__ENTER_srvid);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"login",0);
  tolua_beginmodule(tolua_S,"login");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"DISCONNECT","login::DISCONNECT","",tolua_collect_login__DISCONNECT);
   #else
   tolua_cclass(tolua_S,"DISCONNECT","login::DISCONNECT","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"DISCONNECT");
    tolua_function(tolua_S,"new",tolua_proto_login_DISCONNECT_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_login_DISCONNECT_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_login_DISCONNECT_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_login_DISCONNECT_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_login_DISCONNECT_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_login_DISCONNECT_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_login_DISCONNECT_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_login_DISCONNECT_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_login_DISCONNECT_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_login_DISCONNECT_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_login_DISCONNECT_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_login_DISCONNECT_serialize00);
    tolua_variable(tolua_S,"remain_time",tolua_get_login__DISCONNECT_remain_time,tolua_set_login__DISCONNECT_remain_time);
    tolua_variable(tolua_S,"err",tolua_get_login__DISCONNECT_err,tolua_set_login__DISCONNECT_err);
    tolua_variable(tolua_S,"reason",tolua_get_login__DISCONNECT_reason,tolua_set_login__DISCONNECT_reason);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"account",0);
  tolua_beginmodule(tolua_S,"account");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"REGIST","account::REGIST","",tolua_collect_account__REGIST);
   #else
   tolua_cclass(tolua_S,"REGIST","account::REGIST","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"REGIST");
    tolua_function(tolua_S,"new",tolua_proto_account_REGIST_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_account_REGIST_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_account_REGIST_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_account_REGIST_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_account_REGIST_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_account_REGIST_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_account_REGIST_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_account_REGIST_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_account_REGIST_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_account_REGIST_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_account_REGIST_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_account_REGIST_serialize00);
    tolua_variable(tolua_S,"password",tolua_get_account__REGIST_password,tolua_set_account__REGIST_password);
    tolua_variable(tolua_S,"err",tolua_get_account__REGIST_err,tolua_set_account__REGIST_err);
    tolua_variable(tolua_S,"email",tolua_get_account__REGIST_email,tolua_set_account__REGIST_email);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"regist",0);
  tolua_beginmodule(tolua_S,"regist");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CREATE","regist::CREATE","",tolua_collect_regist__CREATE);
   #else
   tolua_cclass(tolua_S,"CREATE","regist::CREATE","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CREATE");
    tolua_function(tolua_S,"new",tolua_proto_regist_CREATE_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_regist_CREATE_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_regist_CREATE_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_regist_CREATE_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_regist_CREATE_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_regist_CREATE_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_regist_CREATE_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_regist_CREATE_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_regist_CREATE_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_regist_CREATE_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_regist_CREATE_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_regist_CREATE_serialize00);
    tolua_variable(tolua_S,"platform_id",tolua_get_regist__CREATE_platform_id,tolua_set_regist__CREATE_platform_id);
    tolua_variable(tolua_S,"err",tolua_get_regist__CREATE_err,tolua_set_regist__CREATE_err);
    tolua_variable(tolua_S,"role_type",tolua_get_regist__CREATE_role_type,tolua_set_regist__CREATE_role_type);
    tolua_variable(tolua_S,"uname",tolua_get_regist__CREATE_uname,tolua_set_regist__CREATE_uname);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"sdk91",0);
  tolua_beginmodule(tolua_S,"sdk91");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"LOGIN","sdk91::LOGIN","",tolua_collect_sdk91__LOGIN);
   #else
   tolua_cclass(tolua_S,"LOGIN","sdk91::LOGIN","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"LOGIN");
    tolua_function(tolua_S,"new",tolua_proto_sdk91_LOGIN_new00);
    tolua_function(tolua_S,"new_local",tolua_proto_sdk91_LOGIN_new00_local);
    tolua_function(tolua_S,".call",tolua_proto_sdk91_LOGIN_new00_local);
    tolua_function(tolua_S,"delete",tolua_proto_sdk91_LOGIN_delete00);
    tolua_function(tolua_S,"clear",tolua_proto_sdk91_LOGIN_clear00);
    tolua_function(tolua_S,"debug_string",tolua_proto_sdk91_LOGIN_debug_string00);
    tolua_function(tolua_S,"msgname",tolua_proto_sdk91_LOGIN_msgname00);
    tolua_function(tolua_S,"bytesize",tolua_proto_sdk91_LOGIN_bytesize00);
    tolua_function(tolua_S,"tostring",tolua_proto_sdk91_LOGIN_tostring00);
    tolua_function(tolua_S,"parse_from_string",tolua_proto_sdk91_LOGIN_parse_from_string00);
    tolua_function(tolua_S,"parse_from_buf",tolua_proto_sdk91_LOGIN_parse_from_buf00);
    tolua_function(tolua_S,"serialize",tolua_proto_sdk91_LOGIN_serialize00);
    tolua_variable(tolua_S,"uid",tolua_get_sdk91__LOGIN_uid,tolua_set_sdk91__LOGIN_uid);
    tolua_variable(tolua_S,"time",tolua_get_sdk91__LOGIN_time,tolua_set_sdk91__LOGIN_time);
    tolua_variable(tolua_S,"session_id",tolua_get_sdk91__LOGIN_session_id,tolua_set_sdk91__LOGIN_session_id);
    tolua_variable(tolua_S,"err",tolua_get_sdk91__LOGIN_err,tolua_set_sdk91__LOGIN_err);
    tolua_variable(tolua_S,"params",tolua_get_sdk91__LOGIN_params,tolua_set_sdk91__LOGIN_params);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 extern "C"{
 TOLUA_API int luaopen_proto (lua_State* tolua_S) {
 return tolua_proto_open(tolua_S);
};
}
#endif

