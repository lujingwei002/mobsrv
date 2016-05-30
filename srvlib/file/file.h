#ifndef __FILE_H__
#define __FILE_H__ 

namespace File 
{
    char *getcwd();
    bool chdir(const char* dir);
    bool mkdirs(const char* dir);
    bool mkdir(const char* dir);
    bool exists(const char* dir);
    bool remove(const char* dir);
    bool rename(const char* src, const char* dst);
};

#endif
