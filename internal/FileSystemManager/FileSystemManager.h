#pragma once

#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;

class FileSystemManager
{
private:

public:

	static bool verify_existence(string name);
	static list<string> getAllDirFiles(string dir);

};

