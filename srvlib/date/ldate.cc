#include "stdafx.h"

static int lmsectime(lua_State *L){
    struct timeval tv; 
    struct timezone tz; 
    gettimeofday(&tv,&tz);
    long long msec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    lua_pushnumber(L, msec);
    return 1;
}

static int lgettimeofday(lua_State *L){
    struct timeval tv; 
    struct timezone tz; 
    gettimeofday(&tv,&tz);
    lua_pushinteger(L,tv.tv_sec);
    lua_pushinteger(L,tv.tv_usec);
    return 2;
}

static int ltime(lua_State *L){
    int t = time(NULL);
    lua_pushinteger(L, t);
    return 1;
}

static int lstrftime(lua_State *L){
    if(lua_gettop(L) == 2 && lua_isstring(L, 1) && lua_isnumber(L, 2)){
        const char *format = (const char *)lua_tostring(L, 1);
        time_t time = (time_t)lua_tonumber(L, 2);
        struct tm *tm;
        tm = localtime(&time);
        char str[32];
        if(strftime(str, sizeof(str), format, tm)){
        }
        lua_pushstring(L, str);
        return 1;
    }
    return 0;
}

static int lissameday(lua_State *L)
{
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
		time_t t1 = (time_t)lua_tonumber(L, 1);
		time_t t2 = time(NULL);
        struct tm tm1;
        localtime_r(&t1, &tm1);
        struct tm tm2;
        localtime_r(&t2, &tm2);
        if(tm1.tm_year == tm2.tm_year &&
           tm1.tm_mon == tm2.tm_mon && 
           tm1.tm_mday == tm2.tm_mday){
            lua_pushboolean(L, 1);
            return 1;
        }
        lua_pushboolean(L, 0);
        return 1;
	}
    return 0;
}

static int lissamemonth(lua_State *L)
{
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1))
    {
		time_t t1 = (time_t)lua_tonumber(L, 1);
		time_t t2 = time(NULL);
        struct tm tm1;
        localtime_r(&t1, &tm1);
        struct tm tm2;
        localtime_r(&t2, &tm2);
        if(tm1.tm_year == tm2.tm_year &&
           tm1.tm_mon == tm2.tm_mon){
            lua_pushboolean(L, 1);
            return 1;
        }
        lua_pushboolean(L, 0);
        return 1;
	}
    return 0;
}

static int lissameweek(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isnumber(L, 1)){
		time_t t1 = (time_t)lua_tonumber(L, 1);
		time_t t2 = time(NULL);
        struct tm tm1;
        localtime_r(&t1, &tm1);
        struct tm tm2;
        localtime_r(&t2, &tm2);
        if(tm1.tm_year != tm2.tm_year){
            lua_pushboolean(L, 0);
            return 1;
        }
        if(tm1.tm_yday == tm2.tm_yday){
            lua_pushboolean(L, 1);
            return 1;
        }
        if(tm1.tm_yday > tm2.tm_yday && tm1.tm_yday - tm2.tm_yday <= tm1.tm_wday){
            lua_pushboolean(L, 1);
            return 1;
        }
        if(tm1.tm_yday < tm2.tm_yday && tm2.tm_yday - tm1.tm_yday <= 6 - tm1.tm_wday){
            lua_pushboolean(L, 1);
            return 1;
        }
        lua_pushboolean(L, 0);
        return 1;
	}
    return 0;
}

static luaL_Reg lua_lib[] ={
    {"issameweek", lissameweek},
    {"issamemonth", lissamemonth},
    {"issameday", lissameday},
    {"gettimeofday", lgettimeofday},
    {"time", ltime},
    {"msectime", lmsectime},
    {"strftime", lstrftime},
    {NULL, NULL}
};

int luaopen_date(lua_State *L){
	luaL_register(L, "Date", lua_lib);
	return 1;
}

