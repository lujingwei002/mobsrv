#ifndef __LSTRC_H__
#define __LSTRC_H__

typedef int int32;
typedef long long int64;

class LuaStruct {
public:
    LuaStruct() {
        msg = 0;
        isdirty = 0;
        root = this;
    }
    void *msg;
    int isdirty;
    void *root;
};

#endif
