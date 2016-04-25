#ifndef __FILE_H__
#define __FILE_H__ 

namespace File {
    char *getcwd();
    bool chdir(char* dir);
    bool mkdirs(char* dir);
    bool mkdir(char* dir);
    bool exists(char* dir);
    bool remove(char* dir);
    bool rename(char* src, char* dst);
};

#endif
