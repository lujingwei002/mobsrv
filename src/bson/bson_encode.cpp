#include "bson_encode.h"
#include "cBson.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <ctype.h>
#include "log.h"



static int bson_encode_append(lua_State *L,bson *b,const char *key);
static void bson_decode_tree(lua_State* L, bson_iterator* b,int set_t = 0);

bson* bson_encode(lua_State *L)
{
    int type = lua_type(L,-1);
    if(type == LUA_TNIL){
        bson *b = cBSON_CreateNull();
        return b;
    }else if(type == LUA_TBOOLEAN){
        int boo = lua_toboolean(L, -1);
        bson* b = cBSON_CreateBool(boo);
        return b;
    }else if(type == LUA_TNUMBER){
        double num = lua_tonumber(L, -1);
        bson* b = cBSON_CreateNumber(num);
        return b;
    }else if(type == LUA_TSTRING){
        size_t str_len;
        const char *string = lua_tolstring(L, -1, &str_len);
        bson* b = cBSON_CreateString(string);
        return b;
    }else if(type == LUA_TTABLE){
        bson *item = bson_alloc();
        if(item == NULL){
            LOG_ERROR("null");
            return NULL;
        }
        bson_init(item);
        bson_append_start_array(item,"0");
        lua_pushnil(L);
        while(lua_next(L, -2) != 0){
            if(lua_type(L, -2) == LUA_TSTRING){
                size_t str_len = 0;
                const char *k = lua_tolstring(L, -2, &str_len);
                bson_encode_append(L,item,k);
            }else if(lua_type(L, -2) == LUA_TNUMBER){
                int k = (int)lua_tonumber(L, -2);
                char kname[32];
                sprintf(kname, "%d", k);
                bson_encode_append(L,item,kname);
            }
            lua_pop(L, 1);
        }
        bson_append_finish_array(item);
        bson_finish(item);
        return item;
    }
    LOG_ERROR("unspport type");
    return NULL;

}

static int bson_encode_append(lua_State *L,bson *b,const char *key){
    int type = lua_type(L,-1);
    if(type == LUA_TNIL){
    }else if(type == LUA_TBOOLEAN){
        cBSON_AppendBool(L,b,key);
        return 0;
    }else if(type == LUA_TNUMBER){
        cBSON_AppendNumber(L,b,key);
        return 0;
    }else if(type == LUA_TSTRING){
        cBSON_AppendString(L,b,key);
        return 0;
    }else if(type == LUA_TTABLE){
        bson_append_start_array(b,"0");
        lua_pushnil(L);
        while(lua_next(L, -2) != 0){
            if(lua_type(L, -2) == LUA_TSTRING){
                size_t str_len = 0;
                const char *k = lua_tolstring(L, -2, &str_len);
                if(bson_encode_append(L,b,k) != 0){
                    LOG_ERROR("append fail");
                    break;
                }
            }else if(lua_type(L, -2) == LUA_TNUMBER){
                int k = (int)lua_tonumber(L, -2);
                if(b == NULL){
                    LOG_ERROR("null");
                    break;
                }
                char kname[32];
                sprintf(kname, "%d", k);
                if(bson_encode_append(L,b,kname) != 0){
                    LOG_ERROR("append fail");
                }
            }
            lua_pop(L, 1);
        }
        bson_append_finish_array(b);
        return 0;
    }
    LOG_ERROR("unspport type");
    return 1;

}

int bson_decode(lua_State* L, const bson *b_lua){
    bson_iterator b;
    bson_iterator_init(&b,b_lua);
    bson_decode_tree(L, &b);
    return 1;
}
static void bson_decode_tree(lua_State* L, bson_iterator* b,int set_t){
    const char *key;
    while(bson_iterator_next(b))
    {
        bson_type t = bson_iterator_type(b);
        if(t == 0)
        {
            lua_pushnil(L);
            break;
        }
        key = bson_iterator_key(b);
        if(set_t)
        {
            lua_pushstring(L,key);
        }
        LOG_MSG("type %d,key %s",t,key);
        switch(t)
        {
            case BSON_DOUBLE:
                lua_pushnumber(L,bson_iterator_double(b));
                break;
            case BSON_STRING:
                lua_pushstring(L,bson_iterator_string(b));
                break;
            case BSON_BOOL:
                lua_pushboolean(L,bson_iterator_bool( b ) ? true : false );
                break;
            case BSON_NULL:
                lua_pushnil(L);
                break;
            case BSON_INT:
                lua_pushinteger(L,bson_iterator_int(b));
                break;
            case BSON_OBJECT:
                bson_iterator t;
                bson_iterator_subiterator(b,&t);
                bson_decode_tree(L,&t);
                lua_settable(L,-3);
                break;
            case BSON_ARRAY:
                lua_newtable(L);
                bson_iterator s;
                bson_iterator_subiterator(b,&s);
                bson_decode_tree(L,&s,1);
                break;
            default:
                break;
        }
        if(set_t)
        {
            lua_settable(L,-3);
        }
    }

}

static int Encode(lua_State *L){
    bson* b = bson_encode(L);
    if(b == NULL){
        LOG_ERROR("null");
        return -1;
    } 
    bson_print(b);
    bson* bson_field = (bson*) lua_newuserdata(L,sizeof(bson));
    if(bson_field == NULL)
    {
        LOG_ERROR("null");
        return -1;
    }
    int ret = bson_copy(bson_field,b);
    if(ret != 0)
    {
        LOG_ERROR("copy fail");
    }
    //bson_print(bson_field);
    luaL_getmetatable(L,"bson");
    lua_setmetatable(L,-2);
    bson_destroy(b);
    return 1;
}

static int Decode(lua_State *L){
    bson *b_lua = (bson *)luaL_checkudata(L,1,"bson");
    if(b_lua == NULL){
        LOG_ERROR("null");
        return 0;
    }
    if(bson_decode(L, b_lua) == 0){
        LOG_ERROR("decode fail");
        return 0;
    }
    return 1;
}

static luaL_Reg lua_lib[] = {
    {"Encode", Encode},
    {"Decode", Decode},
    {NULL, NULL}
};

int bson_regist(lua_State *L){
	luaL_register(L, "BSON", (luaL_Reg*)lua_lib);
    luaL_newmetatable(L,"bson");
    return 1;
}


