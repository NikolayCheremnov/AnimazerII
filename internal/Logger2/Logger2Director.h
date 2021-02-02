#pragma once

#include "Logger2BuilderI.h"
#include <string>

using namespace std;

class Logger2Director
{
private:
	string ID;
	Logger2BuilderI* Logger2Builder;

public:
	Logger2Director(string ID, Logger2BuilderI* builder);
	~Logger2Director() { delete Logger2Builder; }
	Logger2* Construct();
};

