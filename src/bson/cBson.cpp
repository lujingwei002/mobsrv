#include "cBson.h"
#include "log.h"

bson* cBSON_CreateNull()
{
    bson *item = bson_alloc();
    if(item){
        bson_init_empty(item);
        bson_finish(item);
        return item;
    }
    return NULL;
}

bson* cBSON_CreateBool(int data)
{
    bson *item = bson_alloc();
    if(item){
        bson_init(item);
        bson_append_bool(item,"0",data);
        bson_finish(item);
        return item;
    }
    return NULL;
}

bson* cBSON_CreateNumber(double data)
{
    bson *item = bson_alloc();
    if(item){
        bson_init(item);
        bson_append_double(item,"0",data);
        bson_finish(item);
        return item;
    }
    return NULL;
}

bson* cBSON_CreateString(const char* string)
{
    bson *item = bson_alloc();
    if(item){
        bson_init(item);
        bson_append_string(item,"0",string);
        bson_finish(item);
        return item;
    }
    return NULL;
}
int cBSON_AppendBool(lua_State *L,bson *b,const char *key)
{
    if(b){
        bson_append_bool(b,key,lua_toboolean(L, -1));
        return 0;
    }
    return NULL;
}

int cBSON_AppendNumber(lua_State *L,bson *b,const char *key)
{
    if(b){
        int fail = bson_append_int(b,key,lua_tonumber(L, -1));
        if(fail){
            LOG_ERROR("append int fail,reason %d\n",fail);
        }
        return fail;
    }
    return NULL;
}

int cBSON_AppendString(lua_State *L,bson *b,const char *key)
{
    if(b){
        size_t str_len;
        int fail = bson_append_string(b,key,lua_tolstring(L, -1, &str_len));
        if(fail){
            LOG_ERROR("append string fail,reason %d\n",fail);
        }
        return fail;
    }
    return NULL;
}
