#include "account.pb.h"
#include "login.pb.h"
#include "regist.pb.h"
#include "sdk91.pb.h"
#include "sys.pb.h"
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor_database.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/compiler/importer.h>

int account_LOGIN_tostring(account::LOGIN* self, lua_State* L);
int account_LOGIN_parse_from_string(account::LOGIN* self, lua_State* L);
int account_LOGIN_parse_from_buf(account::LOGIN* self, lua_State* L);
int account_LOGIN_serialize(account::LOGIN* self, lua_State* L);
int sys_TEST_tostring(sys::TEST* self, lua_State* L);
int sys_TEST_parse_from_string(sys::TEST* self, lua_State* L);
int sys_TEST_parse_from_buf(sys::TEST* self, lua_State* L);
int sys_TEST_serialize(sys::TEST* self, lua_State* L);
int login_LOGIN_tostring(login::LOGIN* self, lua_State* L);
int login_LOGIN_parse_from_string(login::LOGIN* self, lua_State* L);
int login_LOGIN_parse_from_buf(login::LOGIN* self, lua_State* L);
int login_LOGIN_serialize(login::LOGIN* self, lua_State* L);
int sys_GM_tostring(sys::GM* self, lua_State* L);
int sys_GM_parse_from_string(sys::GM* self, lua_State* L);
int sys_GM_parse_from_buf(sys::GM* self, lua_State* L);
int sys_GM_serialize(sys::GM* self, lua_State* L);
int login_PING_tostring(login::PING* self, lua_State* L);
int login_PING_parse_from_string(login::PING* self, lua_State* L);
int login_PING_parse_from_buf(login::PING* self, lua_State* L);
int login_PING_serialize(login::PING* self, lua_State* L);
int sys_PING_tostring(sys::PING* self, lua_State* L);
int sys_PING_parse_from_string(sys::PING* self, lua_State* L);
int sys_PING_parse_from_buf(sys::PING* self, lua_State* L);
int sys_PING_serialize(sys::PING* self, lua_State* L);
int login_ENTER_tostring(login::ENTER* self, lua_State* L);
int login_ENTER_parse_from_string(login::ENTER* self, lua_State* L);
int login_ENTER_parse_from_buf(login::ENTER* self, lua_State* L);
int login_ENTER_serialize(login::ENTER* self, lua_State* L);
int login_DISCONNECT_tostring(login::DISCONNECT* self, lua_State* L);
int login_DISCONNECT_parse_from_string(login::DISCONNECT* self, lua_State* L);
int login_DISCONNECT_parse_from_buf(login::DISCONNECT* self, lua_State* L);
int login_DISCONNECT_serialize(login::DISCONNECT* self, lua_State* L);
int account_REGIST_tostring(account::REGIST* self, lua_State* L);
int account_REGIST_parse_from_string(account::REGIST* self, lua_State* L);
int account_REGIST_parse_from_buf(account::REGIST* self, lua_State* L);
int account_REGIST_serialize(account::REGIST* self, lua_State* L);
int regist_CREATE_tostring(regist::CREATE* self, lua_State* L);
int regist_CREATE_parse_from_string(regist::CREATE* self, lua_State* L);
int regist_CREATE_parse_from_buf(regist::CREATE* self, lua_State* L);
int regist_CREATE_serialize(regist::CREATE* self, lua_State* L);
int sdk91_LOGIN_tostring(sdk91::LOGIN* self, lua_State* L);
int sdk91_LOGIN_parse_from_string(sdk91::LOGIN* self, lua_State* L);
int sdk91_LOGIN_parse_from_buf(sdk91::LOGIN* self, lua_State* L);
int sdk91_LOGIN_serialize(sdk91::LOGIN* self, lua_State* L);
