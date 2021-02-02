#include "Logger.h"

// standard in the console
Logger::Logger()
{
	stream_buffer_clog = clog.rdbuf();
	test();
}

Logger::~Logger()
{
	if (logFile != nullptr)
		redirect_clog_to_console();
}

void Logger::redirect_clog_to_file(string fname)
{
	// redirection
	logFile = new fstream(fname, ios::out);
	stream_buffer_file = logFile->rdbuf();
	clog.rdbuf(stream_buffer_file);
}

void Logger::redirect_clog_to_console()
{
	// redirection
	clog.rdbuf(stream_buffer_clog);
	// release resources
	logFile->close();
	delete logFile;
	logFile = nullptr;
	stream_buffer_file = nullptr;
}

void Logger::log(const char* function, string class_role, string method_role, string id, string msg)
{
	string buf(function);
	int colonPos = buf.find(':');
	string class_name = buf.substr(0, colonPos);
	string method_name = buf.substr(colonPos + 2);
	// output
	clog << "log: " << class_name << '_' << class_role << '_' << id << " : " << method_name;
	if (method_role.length() != 0)
		clog << '_' << method_role;
	clog << " : " << msg << endl;
 }

void Logger::err_log(const char* function, string class_role, string method_role, string id, const char* what)
{
	string buf(function);
	int colonPos = buf.find(':');
	string class_name = buf.substr(0, colonPos);
	string method_name = buf.substr(colonPos + 2);
	// output
	clog << "error: " << class_name << '_' << class_role << '_' << id << " : " << method_name;
	if (method_role.length() != 0)
		clog << '_' << method_role;
	clog << " : " << what << endl;
}


