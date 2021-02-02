#pragma once

#include <string>
#include "Logger2.h"

using namespace std;

class Logger2BuilderI
{
protected:
	string ID;
public:
	Logger2BuilderI(string ID) { this->ID = ID; }
	virtual void MakeLoggersChain() = 0;
	virtual Logger2* getResult() = 0;
};

