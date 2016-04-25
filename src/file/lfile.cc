#include "log.h"
#include <netdb.h>
#include <unistd.h>
#include <execinfo.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <errno.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

static int lgetcwd(lua_State *L){
    char buf[128];
    buf[0] = 0;
	getcwd(buf, sizeof(buf));
    lua_pushstring(L, buf); 
    return 1;
}

static int lchdir(lua_State *L){
	const char *dir = (const char *)lua_tostring(L, 1);
	int error = chdir(dir);
    lua_pushinteger(L, error);
    return 1;
}

static int lmkdirs(lua_State *L){
    size_t i;
	if (lua_gettop(L) == 1 && lua_isstring(L, 1)){
        size_t dir_len = 0;
		char *dir = (char *)lua_tolstring(L, 1, &dir_len);
        for(i = 0; i < dir_len; i++){
            if(dir[i] == '/'){
                char c = dir[i];
                dir[i] = 0;
                if(access(dir, 0)){
                    mkdir(dir, 0777);    
                }
                dir[i] = c;
            }
        }
        if(access(dir, 0)){
            mkdir(dir, 0777);    
        }
        lua_pushboolean(L, 1);
        return 1;
	}
    return 0;
}

static int lmkdir(lua_State *L){
    LOG_LOG("ell");
	if (lua_gettop(L) == 1 && lua_isstring(L, 1)){
		const char *dir = (const char *)lua_tostring(L, 1);
        if(!mkdir(dir, 0777)){
            lua_pushboolean(L, 1);
            return 1;
        }
	}
    return 0;
}

static int lexists(lua_State *L){
    int amode;
	const char *dir;
    dir = (const char *)lua_tostring(L, 1);
    amode = (int)lua_tointeger(L, 2);
    if(!access(dir, amode)) {
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}


static int lremove(lua_State *L){
	const char *filepath = (const char *)lua_tostring(L, 1);
    if(!remove(filepath)) {
        lua_pushboolean(L, 1);
        return 1;
    }
    return 0;
}

static int lbasename(lua_State *L){
    char *name;
    size_t str_len = 0;
    name = (char *)lua_tolstring(L, 1, &str_len);
    int startpos = 0;
    for (int i = str_len - 1; i >= 0; i--) {
        if (name[i] == '/') {
            startpos = i + 1;
            break;
        }
    }
    int endpos = str_len - 1;
    for (int i = str_len - 1; i >= 0; i--) {
        if (name[i] == '.') {
            endpos = i - 1;
            break;
        }
    }
    if (startpos > endpos) {
        lua_pushstring(L, "");
        return 1;
    } else {
        lua_pushlstring(L, name + startpos, endpos - startpos + 1);
        return 1;
    }
}

static int lrename(lua_State *L){
    int error;
	const char *src = (const char *)lua_tostring(L, 1);
	const char *dst = (const char *)lua_tostring(L, 2);
    error = rename(src, dst);
    lua_pushinteger(L, error);
    return 1;
}

/*
 * 
 * 返回值 {{type = 'file|dir', name = ''}, ...}
 */
static int llistdir(lua_State *L){
	if (lua_gettop(L) == 1 && lua_isstring(L, 1)){
		const char *dir_name = (const char *)lua_tostring(L, 1);
        struct dirent *ent;
        DIR *dir = opendir(dir_name);
        if(dir == NULL){
            return 0;
        }
        lua_newtable(L);
        int idx = 1;
        while((ent = readdir(dir)) != NULL){
            if(ent->d_type & DT_DIR || ent->d_type & DT_REG){
                if(strcmp(ent->d_name, ".") == 0){
                    continue;
                }
                if(strcmp(ent->d_name, "..") == 0){
                    continue;
                }
                lua_pushnumber(L, idx++);

                lua_newtable(L);
                lua_pushstring(L, "type");
                if(ent->d_type & DT_DIR){
                    lua_pushstring(L, "dir");
                }
                else{
                    lua_pushstring(L, "file");
                }
                lua_settable(L, -3);

                lua_pushstring(L, "name");
                lua_pushstring(L, ent->d_name);
                lua_settable(L, -3);

                lua_settable(L, -3);
            }
        }
        closedir(dir);
        return 1;
	}
    return 0;
}

static int ltest(lua_State *L){
    printf("test\n");
    //lua_pushinteger(L, 1);
    lua_newtable(L);
    return 1;
}

static luaL_Reg lua_lib[] ={
    {"test", ltest},
    {"chdir", lchdir},
    {"getcwd", lgetcwd},
    {"listdir", llistdir},
    {"mkdir", lmkdir},
    {"mkdirs", lmkdirs},
    {"exists", lexists},
    {"remove", lremove},
    {"rename", lrename},
    {"basename", lbasename},
    {NULL, NULL}
};

extern "C" {
int luaopen_file(lua_State *L){
	luaL_register(L, "File", lua_lib);
	return 1;
}
}
