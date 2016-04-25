#include "proto.h"
int account_LOGIN_tostring(account::LOGIN* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int account_LOGIN_parse_from_string(account::LOGIN* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int account_LOGIN_parse_from_buf(account::LOGIN* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int account_LOGIN_serialize(account::LOGIN* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int sys_TEST_tostring(sys::TEST* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int sys_TEST_parse_from_string(sys::TEST* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int sys_TEST_parse_from_buf(sys::TEST* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int sys_TEST_serialize(sys::TEST* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int login_LOGIN_tostring(login::LOGIN* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int login_LOGIN_parse_from_string(login::LOGIN* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int login_LOGIN_parse_from_buf(login::LOGIN* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int login_LOGIN_serialize(login::LOGIN* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int sys_GM_tostring(sys::GM* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int sys_GM_parse_from_string(sys::GM* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int sys_GM_parse_from_buf(sys::GM* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int sys_GM_serialize(sys::GM* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int login_PING_tostring(login::PING* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int login_PING_parse_from_string(login::PING* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int login_PING_parse_from_buf(login::PING* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int login_PING_serialize(login::PING* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int sys_PING_tostring(sys::PING* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int sys_PING_parse_from_string(sys::PING* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int sys_PING_parse_from_buf(sys::PING* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int sys_PING_serialize(sys::PING* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int login_ENTER_tostring(login::ENTER* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int login_ENTER_parse_from_string(login::ENTER* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int login_ENTER_parse_from_buf(login::ENTER* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int login_ENTER_serialize(login::ENTER* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int login_DISCONNECT_tostring(login::DISCONNECT* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int login_DISCONNECT_parse_from_string(login::DISCONNECT* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int login_DISCONNECT_parse_from_buf(login::DISCONNECT* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int login_DISCONNECT_serialize(login::DISCONNECT* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int account_REGIST_tostring(account::REGIST* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int account_REGIST_parse_from_string(account::REGIST* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int account_REGIST_parse_from_buf(account::REGIST* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int account_REGIST_serialize(account::REGIST* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int regist_CREATE_tostring(regist::CREATE* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int regist_CREATE_parse_from_string(regist::CREATE* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int regist_CREATE_parse_from_buf(regist::CREATE* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int regist_CREATE_serialize(regist::CREATE* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
int sdk91_LOGIN_tostring(sdk91::LOGIN* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int sdk91_LOGIN_parse_from_string(sdk91::LOGIN* self, lua_State* L){
   size_t str_len;
   const char *str = lua_tolstring(L, 2, &str_len);
   if(str == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(str, str_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int sdk91_LOGIN_parse_from_buf(sdk91::LOGIN* self, lua_State* L){
   size_t buf_len;
   const char *buf = (const char *)lua_touserdata(L, 2);
   buf_len = (size_t)lua_tointeger(L, 3);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   google::protobuf::io::ArrayInputStream stream(buf, buf_len);
   if(self->ParseFromZeroCopyStream(&stream) == 0){
       printf("parse fail\n");
       lua_pushboolean(L, false);
       return 1;
   }
   lua_pushboolean(L, true);
   return 1;
}
int sdk91_LOGIN_serialize(sdk91::LOGIN* self, lua_State* L){
   char *buf = (char *)lua_touserdata(L, 2);
   if(buf == NULL){
       printf("null\n");
       return 0;
   }
   char* buf_end = (char *)self->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
   lua_pushboolean(L, true);
   lua_pushinteger(L, buf_end - buf);
   return 1;
}
