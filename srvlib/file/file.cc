#include "file.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

namespace File {

//功能：当前目录
char* getcwd()
{
    static char buf[128];
    buf[0] = 0;
	::getcwd(buf, sizeof(buf));
    return buf;
}

//功能：切换目录
bool chdir(const char *dir)
{
	if(::chdir(dir)) 
    {
        return false;
    }
    return true;
}

//功能：创建目录
bool mkdirs(const char *dir)
{
    size_t i;
    size_t dir_len = 0;
    char* ptr = (char* )dir;
    for(i = 0; i < dir_len; i++)
    {
        if(dir[i] == '/'){
            char c = dir[i];
            ptr[i] = 0;
            if(access(dir, 0))
            {
                ::mkdir(dir, 0777);    
            }
            ptr[i] = c;
        }
    }
    if(access(dir, 0))
    {
        ::mkdir(dir, 0777);    
    }
    return true;
}


//功能：创建目录
bool mkdir(const char* dir)
{
    if(::mkdir(dir, 0777))
    {
        return true;
    }
    return false;
}

//功能：目录或者文件是否已经存在
bool exists(const char *dir)
{
    int amode = 0;
    if(::access(dir, amode)) 
    {
        return false;
    }
    return true;
}

//功能：删除文件或者目录
bool remove(const char *filepath)
{
    if(::remove(filepath)) 
    {
        return false;
    }
    return true;
}


//功能：重命名
bool rename(const char *src, const char *dst)
{
    if(::rename(src, dst)) 
    {
        return false;
    }
    return true;
}

};
