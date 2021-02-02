#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>  
using namespace std;

class Logger2
{
protected:
	string ID;
	string logs_path;
	Logger2* nextLogger;

	vector<string> get_tokens(string l_args, string delimiter);
	string get_time();
	virtual void unhandled_log(string l_args);

public:
	Logger2(string ID);
	virtual ~Logger2();
	virtual void log(int l_type, string l_args) = 0;
	bool set_logs_path(string path);
	void set_nextLogger(Logger2* set) { nextLogger = set; }
};

