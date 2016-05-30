
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
/*
 *  lua_pushluafunction(L, "Hello.world")
 *  lua_pushnumber(L, 11);
 *  lua_call(L, 1, 2)
 *
 * POST(sockfd).Hello.Hello(xx, xx, xx)
 *
 * int      i
 * char*    s
 * char     c
 * float    f
 * double   d
 *
 * lua_vcall("POST.hello", "i", sockfd)
 *
 * lua_dostring("Hello.afaf(d, e)")
 *
 *
 *
 *
 */

int lua_vcall(lua_State* L, int arg_count, int result_count) 
{
    return 0;
}

//login.hello_world
//hello_world
int lua_pushluafunction(lua_State *L, const char *func)
{
    char *start = (char *)func;
    char *class_name = start;
    char *pfunc = start;
    while(*pfunc != 0)
    {
        if(*pfunc == '.' && class_name == start)
        {
            *pfunc = 0;
            lua_getglobal(L, class_name);
            *pfunc = '.';
            if(lua_isnil(L, -1)){
                return 0;
            }
            class_name = pfunc + 1;
        }else if(*pfunc == '.')
        {
            *pfunc = 0;
            lua_pushstring(L, class_name);
            lua_gettable(L, -2);
            *pfunc = '.';
            if(lua_isnil(L, -1))
            {
                return 0;
            }
    	    lua_remove(L, -2);//弹出table
            class_name = pfunc + 1;
        }
        pfunc++;
    }
    if(class_name == start)
    {
        lua_getglobal(L, class_name);
        if(lua_isnil(L, -1))
        {
            return 0;
        }
    }else
    {
        lua_pushstring(L, class_name);
        lua_gettable(L, -2);
        if(lua_isnil(L, -1))
        {
            return 0;
        }
        lua_remove(L, -2);//弹出table
    }
    return 1;     
}

