#include "lstrc.h"
#include "actordb.h"
#include <stdlib.h>
#include <string.h>
extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

typedef int GetMethod(lua_State* L);
typedef int SetMethod(lua_State* L);
typedef int NewMethod(lua_State* L);
typedef int UnpackMethod(void *self, const char *buf, int buflen);

static char *s_tostring_buf;
static int s_tostring_buf_len;

static map<string, NewMethod*> actordb_new_method;

static map<string, GetMethod*> actordb_task_get_method;
static map<string, GetMethod*> actordb_task_func_get_method;
static map<string, SetMethod*> actordb_task_set_method;
static array<UnpackMethod*, 3> actordb_task_unpack_method;

static map<string, GetMethod*> actordb_user_get_method;
static map<string, GetMethod*> actordb_user_func_get_method;
static map<string, SetMethod*> actordb_user_set_method;
static array<UnpackMethod*, 6> actordb_user_unpack_method;

static int read_varint(int64* val, const char *buf, int len) {
   memcpy(val, buf, sizeof(int64));
   return sizeof(int64);
}

static int len_varint(int64 val) {
   return sizeof(int64);
}

static int len_string(string& val) {
   int totallen = 0;
   totallen += len_varint(val.size());
   totallen += val.size();
   return totallen;
}

static int write_buf(const char* src_buf, int src_len, char* buf, int len) {
   memcpy(buf, src_buf, src_len);
   return src_len;
}

static int write_varint(int64 val, char *buf, int len) {
   memcpy(buf, (char *)&val, sizeof(int64));
   return sizeof(int64);
}

static int write_string(string& val, char *buf, int len) {
   int totallen = 0;
   int ir = 0;
   ir = write_varint(val.size(), buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   ir = write_buf(val.c_str(), val.size(), buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   return totallen;
}

Task::Task(){
   this->taskid = 0;
   this->uid = 0;
}

Task::~Task(){
}

int Task::packlen(){
   int totallen = 0;

   totallen += len_varint(2);
   totallen += len_varint(this->taskid);

   totallen += len_varint(1);
   totallen += len_varint(this->uid);
   return totallen;
}

int Task::pack(char *buf, int len){
   int totallen = 0;
   int ir = 0;

   ir = write_varint(2, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   ir = write_varint(this->taskid, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;

   ir = write_varint(1, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   ir = write_varint(this->uid, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   return totallen;
}

int Task::unpack(const char *buf, int buflen){
   int totallen = 0;
   int64 tag = 0;
   int64 varlen = 0;
   int ir = 0;

   while(buflen > 0) {
       ir = read_varint(&tag, buf, buflen);
       buf += ir;
       buflen -= ir;
       totallen += ir;
       ir = read_varint(&varlen, buf, buflen);
       buf += ir;
       buflen -= ir;
       totallen += ir;
       UnpackMethod *method = actordb_task_unpack_method[tag];
       if (method) {
           method(this, buf, buflen);
       }
       buf += varlen;
       buflen -= varlen;
       totallen += varlen;
   }
   return totallen;
}

User::User(){
   this->uid = 0;
   this->task = new Task();
   this->uname = "";
}

User::~User(){
   delete this->task;
}

int User::packlen(){
   int totallen = 0;

   totallen += len_varint(3);
   vector<Task*>::iterator it = this->task_array.begin();
   for(; it != this->task_array.end(); ++it) {
       Task* nest_msg = *it;
       totallen += nest_msg->packlen();
   }

   totallen += len_varint(1);
   totallen += len_varint(this->uid);

   totallen += len_varint(5);
   totallen += this->task->packlen();

   totallen += len_varint(2);
   totallen += len_string(this->uname);
   return totallen;
}

int User::pack(char *buf, int len){
   int totallen = 0;
   int ir = 0;

   ir = write_varint(3, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   vector<Task*>::iterator it = this->task_array.begin();
   for(; it != this->task_array.end(); ++it) {
       Task* nest_msg = *it;
       ir = nest_msg->pack(buf, len);
       buf += ir;
       len -= ir;
       totallen += ir;
   }

   ir = write_varint(1, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   ir = write_varint(this->uid, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;

   ir = write_varint(5, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   ir = this->task->pack(buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;

   ir = write_varint(2, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   ir = write_string(this->uname, buf, len);
   buf += ir;
   len -= ir;
   totallen += ir;
   return totallen;
}

int User::unpack(const char *buf, int buflen){
   int totallen = 0;
   int64 tag = 0;
   int64 varlen = 0;
   int ir = 0;

   while(buflen > 0) {
       ir = read_varint(&tag, buf, buflen);
       buf += ir;
       buflen -= ir;
       totallen += ir;
       ir = read_varint(&varlen, buf, buflen);
       buf += ir;
       buflen -= ir;
       totallen += ir;
       UnpackMethod *method = actordb_user_unpack_method[tag];
       if (method) {
           method(this, buf, buflen);
       }
       buf += varlen;
       buflen -= varlen;
       totallen += varlen;
   }
   return totallen;
}

static int lactordb_new(lua_State* L){
   const char *varname = (const char *)lua_tostring(L, 1);
   NewMethod *method = actordb_new_method[varname];;
   return method(L);
}

static int lactordb_task_get(lua_State* L){
   const char *varname = (const char *)lua_tostring(L, 2);
   if (actordb_task_get_method.find(varname) == actordb_task_get_method.end()) {
       if (actordb_task_func_get_method.find(varname) != actordb_task_func_get_method.end()) {
           lua_pushcfunction(L, actordb_task_func_get_method[varname]);
           return 1;
       }
       printf("get actordb_task_%s not found\n", varname);
       return 0;
   }
   GetMethod *method = actordb_task_get_method[varname];;
   return method(L);
}

static int lactordb_task_set(lua_State* L){
   const char *varname = (const char *)lua_tostring(L, 2);
   if (actordb_task_set_method.find(varname) == actordb_task_set_method.end()) {
       printf("set actordb_task_%s not found\n", varname);
       return 0;
   }
   SetMethod *method = actordb_task_set_method[varname];;
   return method(L);
}

static int lactordb_task_gc(lua_State* L){
   return 0;
}

static int lactordb_task_new(lua_State* L){
   LuaStruct *self = (LuaStruct*)lua_newuserdata(L, sizeof(LuaStruct));
   Task *msg = new Task();
   self->msg = msg;
   self->root = self;
   luaL_getmetatable(L, "TaskClass");
   lua_setmetatable(L, -2);
   return 1;
}

static int lactordb_task_bytesize(lua_State* L){
   LuaStruct *self = (LuaStruct*)lua_touserdata(L, 1);
   Task* msg = (Task *)self->msg;
   lua_pushinteger(L, msg->packlen());
   return 1;
}

static int lactordb_task_tostring(lua_State* L){
   LuaStruct *self = (LuaStruct*)lua_touserdata(L, 1);
   Task* msg = (Task *)self->msg;
   int totallen = msg->packlen();
   if (s_tostring_buf_len < totallen) {
       if (s_tostring_buf != NULL) {
           free(s_tostring_buf);
           s_tostring_buf_len = 0;
       }
       s_tostring_buf = (char *)malloc(totallen);
       if (s_tostring_buf == NULL) {
           return 0;
       }
       s_tostring_buf_len = totallen;
   }
   totallen = msg->pack(s_tostring_buf, s_tostring_buf_len);
   lua_pushlstring(L, s_tostring_buf, totallen);
   return 1;
}

static int lactordb_task_totable(lua_State* L){
   return 0;
}

static int lactordb_task_get_taskid(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   Task* msg = (Task *)self->msg;
   lua_pushnumber(L, msg->taskid);
   return 1;
}

static int lactordb_task_set_taskid(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   Task* msg = (Task *)self->msg;
   long long val = (long long)lua_tonumber(L, 3);
   msg->taskid = (int32)val;
   return 0;
}

static int actordb_task_unpack_taskid(void* self, const char* buf, int buflen){
   return 0;
}

static int lactordb_task_get_uid(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   Task* msg = (Task *)self->msg;
   lua_pushnumber(L, msg->uid);
   return 1;
}

static int lactordb_task_set_uid(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   Task* msg = (Task *)self->msg;
   long long val = (long long)lua_tonumber(L, 3);
   msg->uid = (int32)val;
   return 0;
}

static int actordb_task_unpack_uid(void* self, const char* buf, int buflen){
   return 0;
}

static int lactordb_user_get(lua_State* L){
   const char *varname = (const char *)lua_tostring(L, 2);
   if (actordb_user_get_method.find(varname) == actordb_user_get_method.end()) {
       if (actordb_user_func_get_method.find(varname) != actordb_user_func_get_method.end()) {
           lua_pushcfunction(L, actordb_user_func_get_method[varname]);
           return 1;
       }
       printf("get actordb_user_%s not found\n", varname);
       return 0;
   }
   GetMethod *method = actordb_user_get_method[varname];;
   return method(L);
}

static int lactordb_user_set(lua_State* L){
   const char *varname = (const char *)lua_tostring(L, 2);
   if (actordb_user_set_method.find(varname) == actordb_user_set_method.end()) {
       printf("set actordb_user_%s not found\n", varname);
       return 0;
   }
   SetMethod *method = actordb_user_set_method[varname];;
   return method(L);
}

static int lactordb_user_gc(lua_State* L){
   return 0;
}

static int lactordb_user_new(lua_State* L){
   LuaStruct *self = (LuaStruct*)lua_newuserdata(L, sizeof(LuaStruct));
   User *msg = new User();
   self->msg = msg;
   self->root = self;
   luaL_getmetatable(L, "UserClass");
   lua_setmetatable(L, -2);
   return 1;
}

static int lactordb_user_bytesize(lua_State* L){
   LuaStruct *self = (LuaStruct*)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   lua_pushinteger(L, msg->packlen());
   return 1;
}

static int lactordb_user_tostring(lua_State* L){
   LuaStruct *self = (LuaStruct*)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   int totallen = msg->packlen();
   if (s_tostring_buf_len < totallen) {
       if (s_tostring_buf != NULL) {
           free(s_tostring_buf);
           s_tostring_buf_len = 0;
       }
       s_tostring_buf = (char *)malloc(totallen);
       if (s_tostring_buf == NULL) {
           return 0;
       }
       s_tostring_buf_len = totallen;
   }
   totallen = msg->pack(s_tostring_buf, s_tostring_buf_len);
   lua_pushlstring(L, s_tostring_buf, totallen);
   return 1;
}

static int lactordb_user_totable(lua_State* L){
   return 0;
}

static int lactordb_user_add_task_array(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   Task* nest_msg = new Task();
   msg->task_array.push_back(nest_msg);
   LuaStruct *nest_self = (LuaStruct *)lua_newuserdata(L, sizeof(LuaStruct));
   luaL_getmetatable(L, "TaskClass");
   lua_setmetatable(L, -2);
   nest_self->msg = nest_msg;
   nest_self->root = self->root;
   return 1;
}

static int lactordb_user_get_task_array(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   int index = (int)lua_tointeger(L, 2);
   if (index < 0 || index >= msg->task_array.size()) {
       return 0;
   }
   LuaStruct *nest_self = (LuaStruct *)lua_newuserdata(L, sizeof(LuaStruct));
   luaL_getmetatable(L, "TaskClass");
   lua_setmetatable(L, -2);
   nest_self->msg = msg->task_array[index];
   nest_self->root = self->root;
   return 1;
}

static int lactordb_user_count_task_array(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   int val = msg->task_array.size();
   lua_pushinteger(L, val);
   return 1;
}

static int lactordb_user_del_task_array(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   int index = (int)lua_tointeger(L, 2);
   if (index < 0 || index >= msg->task_array.size()) {
       return 0;
   }
   Task* nest_msg = msg->task_array[index];
   msg->task_array.erase(msg->task_array.begin() + index);
   delete nest_msg;
   lua_pushinteger(L, index);
   return 1;
}

static int actordb_user_unpack_task_array(void*self, const char* buf, int buflen){
   return 0;
}

static int lactordb_user_get_uid(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   lua_pushnumber(L, msg->uid);
   return 1;
}

static int lactordb_user_set_uid(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   long long val = (long long)lua_tonumber(L, 3);
   msg->uid = (int32)val;
   return 0;
}

static int actordb_user_unpack_uid(void* self, const char* buf, int buflen){
   return 0;
}

static int lactordb_user_get_task(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   LuaStruct *nest_self = (LuaStruct *)lua_newuserdata(L, sizeof(LuaStruct));
   luaL_getmetatable(L, "TaskClass");
   lua_setmetatable(L, -2);
   nest_self->msg = msg->task;
   nest_self->root = self->root;
   return 1;
}

static int actordb_user_unpack_task(void* self, const char* buf, int buflen){
   return 0;
}

static int lactordb_user_get_uname(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   lua_pushstring(L, msg->uname.c_str());
   return 1;
}

static int lactordb_user_set_uname(lua_State* L){
   LuaStruct* self = (LuaStruct *)lua_touserdata(L, 1);
   User* msg = (User *)self->msg;
   const char* val = (const char *)lua_tostring(L, 3);
   msg->uname = val;
   return 0;
}

static int actordb_user_unpack_uname(void *self, const char* buf, int buflen){
   return 0;
}
static luaL_Reg lua_lib[] = {
   {"new", lactordb_new},
   {NULL, NULL}
};

extern "C" {
int luaopen_actordb(lua_State* L) {
   luaL_register(L, "Actordb", (luaL_Reg*)lua_lib);
   luaL_newmetatable(L, "TaskClass");
   lua_pushstring(L, "__index");
   lua_pushcfunction(L, lactordb_task_get);
   lua_settable(L, -3);
   lua_pushstring(L, "__newindex");
   lua_pushcfunction(L, lactordb_task_set);
   lua_settable(L, -3);
   lua_pushstring(L, "__gc");
   lua_pushcfunction(L, lactordb_task_gc);
   lua_settable(L, -3);

   luaL_newmetatable(L, "UserClass");
   lua_pushstring(L, "__index");
   lua_pushcfunction(L, lactordb_user_get);
   lua_settable(L, -3);
   lua_pushstring(L, "__newindex");
   lua_pushcfunction(L, lactordb_user_set);
   lua_settable(L, -3);
   lua_pushstring(L, "__gc");
   lua_pushcfunction(L, lactordb_user_gc);
   lua_settable(L, -3);


   actordb_task_func_get_method["totable"] = lactordb_task_totable;
   actordb_task_func_get_method["tostring"] = lactordb_task_tostring;
   actordb_task_func_get_method["bytesize"] = lactordb_task_bytesize;
   actordb_task_unpack_method[2] = actordb_task_unpack_taskid;
   actordb_task_get_method["taskid"] = lactordb_task_get_taskid;
   actordb_task_set_method["taskid"] = lactordb_task_set_taskid;
   actordb_task_unpack_method[1] = actordb_task_unpack_uid;
   actordb_task_get_method["uid"] = lactordb_task_get_uid;
   actordb_task_set_method["uid"] = lactordb_task_set_uid;

   actordb_user_func_get_method["totable"] = lactordb_user_totable;
   actordb_user_func_get_method["tostring"] = lactordb_user_tostring;
   actordb_user_func_get_method["bytesize"] = lactordb_user_bytesize;
   actordb_user_unpack_method[3] = actordb_user_unpack_task_array;
   actordb_user_func_get_method["get_task_array"] = lactordb_user_get_task_array;
   actordb_user_func_get_method["add_task_array"] = lactordb_user_add_task_array;
   actordb_user_func_get_method["count_task_array"] = lactordb_user_count_task_array;
   actordb_user_func_get_method["del_task_array"] = lactordb_user_del_task_array;
   actordb_user_unpack_method[1] = actordb_user_unpack_uid;
   actordb_user_get_method["uid"] = lactordb_user_get_uid;
   actordb_user_set_method["uid"] = lactordb_user_set_uid;
   actordb_user_unpack_method[5] = actordb_user_unpack_task;
   actordb_user_get_method["task"] = lactordb_user_get_task;
   actordb_user_unpack_method[2] = actordb_user_unpack_uname;
   actordb_user_get_method["uname"] = lactordb_user_get_uname;
   actordb_user_set_method["uname"] = lactordb_user_set_uname;

   actordb_new_method["Task"] = lactordb_task_new;
   actordb_new_method["User"] = lactordb_user_new;
   printf("load actordb\n");
   return 1;
}
}
