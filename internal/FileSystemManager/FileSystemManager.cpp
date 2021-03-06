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

list<string> FileSystemManager::getAllDirFilesShort(string dir)
{
    list<string> res;
    if (verify_existence(dir))
        for (const auto& entry : fs::directory_iterator(dir))
            res.push_back(string(entry.path().filename().string()));
    return res;
}

void FileSystemManager::create_subdir(string path, string name)
{
    if (!verify_existence(path))
        throw exception("root path does not exist");
    if (!fs::create_directory(path + "\\" + name))
        throw exception("couldn't create a directory");
    
}

map<string, string> FileSystemManager::read_file_to_map_params(string path)
{
    if (!verify_existence(path))
        throw exception("file does not exist");
    map<string, string> params;
    ifstream file;
    file.open(path);
    string line;
    while (getline(file, line)) {
        string arg = line.substr(0, line.find(':'));
        string value = line.substr(line.find(':') + 1);
        params.insert(pair<string, string>(arg, value));
    } 
    file.close();
    return params;
}

void FileSystemManager::delete_dir_with_all_files(string path)
{
    if (verify_existence(path))
        fs::remove_all(path);
}
