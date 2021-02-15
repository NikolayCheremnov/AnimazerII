#include "FileSystemManager.h"

bool FileSystemManager::verify_existence(string name)
{
    return fs::exists(name);
}

list<string> FileSystemManager::getAllDirFiles(string dir)
{
    list<string> res;
    if (verify_existence(dir))
        for (const auto& entry : fs::directory_iterator(dir))
            res.push_back(string(entry.path().string()));
    return res;
}
