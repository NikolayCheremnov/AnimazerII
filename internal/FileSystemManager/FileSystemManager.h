#pragma once

#include <string>
#include <map>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

using namespace std;

class FileSystemManager
{
private:

public:

	static bool verify_existence(string name);
	static list<string> getAllDirFiles(string dir);
	static list<string> getAllDirFilesShort(string dir);
	static void create_subdir(string path, string name);
	static map<string, string> read_file_to_map_params(string path);
	static void delete_dir_with_all_files(string path);
};

