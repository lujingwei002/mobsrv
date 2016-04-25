#include "achieve.pb.h"
#include "friend.pb.h"
#include "item.pb.h"
#include "mail.pb.h"
#include "player.pb.h"
#include "task.pb.h"
#include "user.pb.h"
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
void dbproto_Task_del_value(dbproto::Task* self, lua_State* L, int index);
void dbproto_TaskData_del_tasks(dbproto::TaskData* self, lua_State* L, int index);
void dbproto_MailList_del_mails(dbproto::MailList* self, lua_State* L, int index);
void dbproto_FriendData_del_friends(dbproto::FriendData* self, lua_State* L, int index);
void dbproto_ItemData_del_items(dbproto::ItemData* self, lua_State* L, int index);
void dbproto_AchieveData_del_achieves(dbproto::AchieveData* self, lua_State* L, int index);
void dbproto_Achieve_del_value(dbproto::Achieve* self, lua_State* L, int index);

int dbproto_Task_tostring(dbproto::Task* self, lua_State* L);
int dbproto_Task_parse_from_string(dbproto::Task* self, lua_State* L);
int dbproto_Task_parse_from_buf(dbproto::Task* self, lua_State* L);
int dbproto_Task_serialize(dbproto::Task* self, lua_State* L);
int dbproto_UserData_Hello_tostring(dbproto::UserData::Hello* self, lua_State* L);
int dbproto_UserData_Hello_parse_from_string(dbproto::UserData::Hello* self, lua_State* L);
int dbproto_UserData_Hello_parse_from_buf(dbproto::UserData::Hello* self, lua_State* L);
int dbproto_UserData_Hello_serialize(dbproto::UserData::Hello* self, lua_State* L);
int dbproto_TaskData_tostring(dbproto::TaskData* self, lua_State* L);
int dbproto_TaskData_parse_from_string(dbproto::TaskData* self, lua_State* L);
int dbproto_TaskData_parse_from_buf(dbproto::TaskData* self, lua_State* L);
int dbproto_TaskData_serialize(dbproto::TaskData* self, lua_State* L);
int dbproto_Item_tostring(dbproto::Item* self, lua_State* L);
int dbproto_Item_parse_from_string(dbproto::Item* self, lua_State* L);
int dbproto_Item_parse_from_buf(dbproto::Item* self, lua_State* L);
int dbproto_Item_serialize(dbproto::Item* self, lua_State* L);
int dbproto_UserData_tostring(dbproto::UserData* self, lua_State* L);
int dbproto_UserData_parse_from_string(dbproto::UserData* self, lua_State* L);
int dbproto_UserData_parse_from_buf(dbproto::UserData* self, lua_State* L);
int dbproto_UserData_serialize(dbproto::UserData* self, lua_State* L);
int dbproto_Friend_tostring(dbproto::Friend* self, lua_State* L);
int dbproto_Friend_parse_from_string(dbproto::Friend* self, lua_State* L);
int dbproto_Friend_parse_from_buf(dbproto::Friend* self, lua_State* L);
int dbproto_Friend_serialize(dbproto::Friend* self, lua_State* L);
int dbproto_MailList_tostring(dbproto::MailList* self, lua_State* L);
int dbproto_MailList_parse_from_string(dbproto::MailList* self, lua_State* L);
int dbproto_MailList_parse_from_buf(dbproto::MailList* self, lua_State* L);
int dbproto_MailList_serialize(dbproto::MailList* self, lua_State* L);
int dbproto_FriendData_tostring(dbproto::FriendData* self, lua_State* L);
int dbproto_FriendData_parse_from_string(dbproto::FriendData* self, lua_State* L);
int dbproto_FriendData_parse_from_buf(dbproto::FriendData* self, lua_State* L);
int dbproto_FriendData_serialize(dbproto::FriendData* self, lua_State* L);
int dbproto_Mail_tostring(dbproto::Mail* self, lua_State* L);
int dbproto_Mail_parse_from_string(dbproto::Mail* self, lua_State* L);
int dbproto_Mail_parse_from_buf(dbproto::Mail* self, lua_State* L);
int dbproto_Mail_serialize(dbproto::Mail* self, lua_State* L);
int dbproto_ItemData_tostring(dbproto::ItemData* self, lua_State* L);
int dbproto_ItemData_parse_from_string(dbproto::ItemData* self, lua_State* L);
int dbproto_ItemData_parse_from_buf(dbproto::ItemData* self, lua_State* L);
int dbproto_ItemData_serialize(dbproto::ItemData* self, lua_State* L);
int dbproto_PlayerData_tostring(dbproto::PlayerData* self, lua_State* L);
int dbproto_PlayerData_parse_from_string(dbproto::PlayerData* self, lua_State* L);
int dbproto_PlayerData_parse_from_buf(dbproto::PlayerData* self, lua_State* L);
int dbproto_PlayerData_serialize(dbproto::PlayerData* self, lua_State* L);
int dbproto_AchieveData_tostring(dbproto::AchieveData* self, lua_State* L);
int dbproto_AchieveData_parse_from_string(dbproto::AchieveData* self, lua_State* L);
int dbproto_AchieveData_parse_from_buf(dbproto::AchieveData* self, lua_State* L);
int dbproto_AchieveData_serialize(dbproto::AchieveData* self, lua_State* L);
int dbproto_Achieve_tostring(dbproto::Achieve* self, lua_State* L);
int dbproto_Achieve_parse_from_string(dbproto::Achieve* self, lua_State* L);
int dbproto_Achieve_parse_from_buf(dbproto::Achieve* self, lua_State* L);
int dbproto_Achieve_serialize(dbproto::Achieve* self, lua_State* L);
