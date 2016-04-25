#include "log.h"
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

static int lopenlevel(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
        int level = (int)lua_tonumber(L, 1);
        log_openlevel(level);
        return 0;
	}
    return 0;
}

static int lcloseall(lua_State *L){
	if (lua_gettop(L) == 0){
        log_closeall();
        return 0;
	}
    return 0;
}

static int lcloselevel(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
        int level = (int)lua_tonumber(L, 1);
        log_closelevel(level);
        return 0;
	}
    return 0;
}

static int llogstat(lua_State *L){

	if (lua_gettop(L) == 3 && lua_isstring(L, 1) && lua_isnumber(L, 2) && lua_isstring(L, 3)){
        char *file_name = (char *)lua_tostring(L, 1);
        int file_max_linenum = (int)lua_tonumber(L, 2);
        char *file_dir = (char *)lua_tostring(L, 3);
        log_logstat(file_name, file_max_linenum, file_dir);
        return 0;
	}
    return 0;
}

static int llogfile(lua_State *L){
	if (lua_gettop(L) == 3 && lua_isstring(L, 1) && lua_isnumber(L, 2) && lua_isstring(L, 3)){
        char *file_name = (char *)lua_tostring(L, 1);
        int file_max_linenum = (int)lua_tonumber(L, 2);
        char *file_dir = (char *)lua_tostring(L, 3);
        log_logfile(file_name, file_max_linenum, file_dir);
        return 0;
	}
    return 0;
}

static int ldebug(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isstring(L, 1)){
        size_t str_len = 0;
        const char *str = (const char *)lua_tolstring(L, 1, &str_len);
        log_print(DEBUG, str, str_len);
        return 0;
	}
    return 0;
}

static int llog(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isstring(L, 1)){
        size_t str_len = 0;
        const char *str = (const char *)lua_tolstring(L, 1, &str_len);
        log_print(LOG, str, str_len);
        return 0;
	}
    return 0;
}

static int lerror(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isstring(L, 1)){
        size_t str_len = 0;
        const char *str = (const char *)lua_tolstring(L, 1, &str_len);
        log_print(ERROR, str, str_len);
        return 0;
	}
    return 0;
}

static int lwarn(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isstring(L, 1)){
        size_t str_len = 0;
        const char *str = (const char *)lua_tolstring(L, 1, &str_len);
        log_print(WARN, str, str_len);
        return 0;
	}
    return 0;
}

static luaL_Reg lua_lib[] ={
    {"closeall", lcloseall},
    {"closelevel", lcloselevel},
    {"openlevel", lopenlevel},
    {"logfile", llogfile},
    {"logstat", llogstat},
    {"log", llog},
    {"error", lerror},
    {"debug", ldebug},
    {"warn", lwarn},
    {NULL, NULL}
};

extern "C" {
int luaopen_log(lua_State *L){
	luaL_register(L, "Log", (luaL_Reg*)lua_lib);
    lua_pushstring(L, "LOG");
    lua_pushinteger(L, LOG);
    lua_settable(L, -3);
    lua_pushstring(L, "ERROR");
    lua_pushinteger(L, ERROR);
    lua_settable(L, -3);
    lua_pushstring(L, "MSG");
    lua_pushinteger(L, MSG);
    lua_settable(L, -3);
    lua_pushstring(L, "WARN");
    lua_pushinteger(L, WARN);
    lua_settable(L, -3);
    lua_pushstring(L, "DEBUG");
    lua_pushinteger(L, DEBUG);
    lua_settable(L, -3);
    lua_pushstring(L, "STAT");
    lua_pushinteger(L, STAT);
    lua_settable(L, -3);
    return 1;
}
}
