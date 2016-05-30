#include "srvapp/srvapp.h"
#include "log/log.h"


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

namespace Srvapp
{
    lua_State* L;

    static void _atexit() 
    {
        LOG_LOG("_atexit");
        if (L != NULL) 
        {
            lua_getglobal(L, "_atexit");
            if(!lua_isnil(L, -1))
            {
                lua_pcall(L, 0, 0, 0);
            }
        }    
    }

    static void sig_int(int b)
    {
        LOG_LOG("sig_int");
        if (L != NULL) 
        {
            lua_getglobal(L, "_atint");
            if(!lua_isnil(L, -1))
            {
                lua_pcall(L, 0, 0, 0);
                return;
            }
        } 
        exit(0);
    }


    int init(int argc, char** argv)
    {
        L = lua_open();
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
        return 0;
    }

    int run()
    {
        if(luaL_dofile(Srvapp::L, "main.lua"))
        {
            if (lua_isstring(L, -1))
            {
                LOG_LOG("dofile error %s\n", lua_tostring(Srvapp::L, -1));
                return 1;
            }
        }
        lua_getglobal(L, "main");
        if (lua_pcall(L, 0, 0, 0) != 0)
        {
            LOG_ERROR("error running main : %s\n", lua_tostring(L, -1));
        }
        lua_pop(L, lua_gettop(L));
        return 0;
    }

    int destory()
    {
        return 0;
    }

    static int ldaemon(lua_State *L)
    {
        int pid;
        pid = fork();
        if(pid)
        {
            exit(0);
        }else if(pid < 0)
        {
            LOG_ERROR("fork error");
            exit(1);
        }
        //setsid();
        //pid = fork();
        //if(pid)
        //{
            //exit(0);
        //}else if(pid < 0){
            //LOG_ERROR("fork error");
            //exit(1);
        //}
        //ps, 关了就不要写
        //for(i = 0; i <=2; i++)
        //{
          //close(i);
        //}
        //忽略ctrl-c
        //signal(SIGINT, SIG_IGN);
        lua_pushboolean(L, 1);
        return 1;
    }
};
