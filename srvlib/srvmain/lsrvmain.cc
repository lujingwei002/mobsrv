#include "stdafx.h"

/*
 *  程序启动的环境初始化
 *  程序结束的清理工作
 */

static lua_State *s_L;

static void _atexit() {
    LOG_LOG("_atexit");
    lua_State *L = s_L;
    if (L != NULL) {
        lua_getglobal(L, "_atexit");
        if(!lua_isnil(L, -1)){
            lua_pcall(L, 0, 0, 0);
        }
    }    
}

static void sig_int(int b){
    LOG_LOG("sig_int");
     lua_State *L = s_L;
    if (L != NULL) {
        lua_getglobal(L, "_atint");
        if(!lua_isnil(L, -1)){
            lua_pcall(L, 0, 0, 0);
            return;
        }
    } 
    exit(0);
}

static int lmain(lua_State *L){
    if (L != NULL) {
        s_L = L;
    }
    atexit(_atexit);
    signal(SIGHUP, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    //往关闭的socket写数据
    signal(SIGPIPE, SIG_IGN);
    //google protobuf出错时候会出这个
    signal(SIGABRT, SIG_IGN);
    //ctrl-c信号
    signal(SIGINT, sig_int);
    lua_pushboolean(L, 1);
    return 1;
}

static int ldaemon(lua_State *L){
    int pid;
    pid = fork();
    if(pid){
        exit(0);
    }else if(pid < 0){
        LOG_ERROR("fork error");
        exit(1);
    }
    /*  
	setsid();
    pid = fork();
    if(pid){
        exit(0);
    }else if(pid < 0){
        LOG_ERROR("fork error");
        exit(1);
    }
    */
    //ps, 关了就不要写
	/*for(i = 0; i <=2; i++){
		close(i);
	}*/
    //忽略ctrl-c
    //signal(SIGINT, SIG_IGN);
    lua_pushboolean(L, 1);
    return 1;
}

static luaL_Reg lua_lib[] =
{
    {"daemon", ldaemon},
    {"main", lmain},
    {NULL, NULL}
};

int luaopen_srvmain(lua_State *L)
{
	luaL_register(L, "Srvmain", lua_lib);
	return 1;
}

