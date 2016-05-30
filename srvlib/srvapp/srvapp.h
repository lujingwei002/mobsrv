#ifndef __SRVAPP_H__
#define __SRVAPP_H__


extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


namespace Srvapp
{

    extern lua_State* L;

    int init(int argc, char** argv);
    int run();
    int destory();

};

#endif
