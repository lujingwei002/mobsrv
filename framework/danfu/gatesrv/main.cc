#include "stdafx.h"

int main(int argc, char** argv)
{
    Srvapp::init(argc, argv);
    luaL_openlibs(Srvapp::L);
    luaopen_srvlib(Srvapp::L);
    Srvapp::run();
    Srvapp::destory();
    return 0;
}

