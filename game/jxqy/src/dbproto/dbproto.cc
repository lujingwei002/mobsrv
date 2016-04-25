#include "dbproto.h"
int dbproto_Task_tostring(dbproto::Task* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_Task_parse_from_string(dbproto::Task* self, lua_State* L){
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
int dbproto_Task_parse_from_buf(dbproto::Task* self, lua_State* L){
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
int dbproto_Task_serialize(dbproto::Task* self, lua_State* L){
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
void dbproto_Task_del_value(dbproto::Task *self, lua_State* L, int index) {
   if (index < 0 || index >= self->value_size()) {
       printf("index invalid index(%d)\n", index);
       return;
   }
   self->mutable_value()->SwapElements(index, self->value_size() - 1);
   self->mutable_value()->RemoveLast();
}
int dbproto_UserData_Hello_tostring(dbproto::UserData::Hello* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_UserData_Hello_parse_from_string(dbproto::UserData::Hello* self, lua_State* L){
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
int dbproto_UserData_Hello_parse_from_buf(dbproto::UserData::Hello* self, lua_State* L){
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
int dbproto_UserData_Hello_serialize(dbproto::UserData::Hello* self, lua_State* L){
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
int dbproto_TaskData_tostring(dbproto::TaskData* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_TaskData_parse_from_string(dbproto::TaskData* self, lua_State* L){
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
int dbproto_TaskData_parse_from_buf(dbproto::TaskData* self, lua_State* L){
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
int dbproto_TaskData_serialize(dbproto::TaskData* self, lua_State* L){
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
void dbproto_TaskData_del_tasks(dbproto::TaskData *self, lua_State* L, int index) {
   if (index < 0 || index >= self->tasks_size()) {
       printf("index invalid index(%d)\n", index);
       return;
   }
   self->mutable_tasks()->SwapElements(index, self->tasks_size() - 1);
   self->mutable_tasks()->RemoveLast();
}
int dbproto_Item_tostring(dbproto::Item* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_Item_parse_from_string(dbproto::Item* self, lua_State* L){
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
int dbproto_Item_parse_from_buf(dbproto::Item* self, lua_State* L){
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
int dbproto_Item_serialize(dbproto::Item* self, lua_State* L){
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
int dbproto_UserData_tostring(dbproto::UserData* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_UserData_parse_from_string(dbproto::UserData* self, lua_State* L){
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
int dbproto_UserData_parse_from_buf(dbproto::UserData* self, lua_State* L){
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
int dbproto_UserData_serialize(dbproto::UserData* self, lua_State* L){
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
int dbproto_Friend_tostring(dbproto::Friend* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_Friend_parse_from_string(dbproto::Friend* self, lua_State* L){
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
int dbproto_Friend_parse_from_buf(dbproto::Friend* self, lua_State* L){
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
int dbproto_Friend_serialize(dbproto::Friend* self, lua_State* L){
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
int dbproto_MailList_tostring(dbproto::MailList* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_MailList_parse_from_string(dbproto::MailList* self, lua_State* L){
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
int dbproto_MailList_parse_from_buf(dbproto::MailList* self, lua_State* L){
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
int dbproto_MailList_serialize(dbproto::MailList* self, lua_State* L){
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
void dbproto_MailList_del_mails(dbproto::MailList *self, lua_State* L, int index) {
   if (index < 0 || index >= self->mails_size()) {
       printf("index invalid index(%d)\n", index);
       return;
   }
   self->mutable_mails()->SwapElements(index, self->mails_size() - 1);
   self->mutable_mails()->RemoveLast();
}
int dbproto_FriendData_tostring(dbproto::FriendData* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_FriendData_parse_from_string(dbproto::FriendData* self, lua_State* L){
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
int dbproto_FriendData_parse_from_buf(dbproto::FriendData* self, lua_State* L){
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
int dbproto_FriendData_serialize(dbproto::FriendData* self, lua_State* L){
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
void dbproto_FriendData_del_friends(dbproto::FriendData *self, lua_State* L, int index) {
   if (index < 0 || index >= self->friends_size()) {
       printf("index invalid index(%d)\n", index);
       return;
   }
   self->mutable_friends()->SwapElements(index, self->friends_size() - 1);
   self->mutable_friends()->RemoveLast();
}
int dbproto_Mail_tostring(dbproto::Mail* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_Mail_parse_from_string(dbproto::Mail* self, lua_State* L){
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
int dbproto_Mail_parse_from_buf(dbproto::Mail* self, lua_State* L){
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
int dbproto_Mail_serialize(dbproto::Mail* self, lua_State* L){
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
int dbproto_ItemData_tostring(dbproto::ItemData* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_ItemData_parse_from_string(dbproto::ItemData* self, lua_State* L){
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
int dbproto_ItemData_parse_from_buf(dbproto::ItemData* self, lua_State* L){
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
int dbproto_ItemData_serialize(dbproto::ItemData* self, lua_State* L){
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
void dbproto_ItemData_del_items(dbproto::ItemData *self, lua_State* L, int index) {
   if (index < 0 || index >= self->items_size()) {
       printf("index invalid index(%d)\n", index);
       return;
   }
   self->mutable_items()->SwapElements(index, self->items_size() - 1);
   self->mutable_items()->RemoveLast();
}
int dbproto_PlayerData_tostring(dbproto::PlayerData* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_PlayerData_parse_from_string(dbproto::PlayerData* self, lua_State* L){
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
int dbproto_PlayerData_parse_from_buf(dbproto::PlayerData* self, lua_State* L){
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
int dbproto_PlayerData_serialize(dbproto::PlayerData* self, lua_State* L){
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
int dbproto_AchieveData_tostring(dbproto::AchieveData* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_AchieveData_parse_from_string(dbproto::AchieveData* self, lua_State* L){
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
int dbproto_AchieveData_parse_from_buf(dbproto::AchieveData* self, lua_State* L){
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
int dbproto_AchieveData_serialize(dbproto::AchieveData* self, lua_State* L){
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
void dbproto_AchieveData_del_achieves(dbproto::AchieveData *self, lua_State* L, int index) {
   if (index < 0 || index >= self->achieves_size()) {
       printf("index invalid index(%d)\n", index);
       return;
   }
   self->mutable_achieves()->SwapElements(index, self->achieves_size() - 1);
   self->mutable_achieves()->RemoveLast();
}
int dbproto_Achieve_tostring(dbproto::Achieve* self, lua_State* L){
   std::string str;
   if(!self->SerializeToString(&str)) {
       printf("SerializeToString fail\n");
       return 0;
   }
   lua_pushlstring(L, str.data(), str.size());
   return 1;
}
int dbproto_Achieve_parse_from_string(dbproto::Achieve* self, lua_State* L){
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
int dbproto_Achieve_parse_from_buf(dbproto::Achieve* self, lua_State* L){
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
int dbproto_Achieve_serialize(dbproto::Achieve* self, lua_State* L){
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
void dbproto_Achieve_del_value(dbproto::Achieve *self, lua_State* L, int index) {
   if (index < 0 || index >= self->value_size()) {
       printf("index invalid index(%d)\n", index);
       return;
   }
   self->mutable_value()->SwapElements(index, self->value_size() - 1);
   self->mutable_value()->RemoveLast();
}
