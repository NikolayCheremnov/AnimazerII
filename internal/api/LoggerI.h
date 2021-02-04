#include <string>

using namespace std;

#pragma once
class LoggerI
{
public:
	virtual void log(int arg, string string) = 0;
};

