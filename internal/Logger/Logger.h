#pragma once

#include <iostream>
#include <fstream>

using namespace std;
// logger class
class Logger
{
private:
	fstream* logFile = nullptr;
	streambuf* stream_buffer_clog;
	streambuf* stream_buffer_file = nullptr;

public:
	Logger();
	~Logger();
	// logger test
	void test() { clog << "Animazer logger v1 by Nikolay Cheremnov."; }
	// switchers
	void redirect_clog_to_file(string fname);
	void redirect_clog_to_console();
	// loggers
	void log(const char* function, string class_role, string method_role, string id, string msg);
	void err_log(const char* function, string class_role, string method_role, string id, const char* what);
};

