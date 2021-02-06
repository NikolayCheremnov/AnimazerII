#pragma once

#include <string>

using namespace std;

class ProcessorI
{
protected:
	string ID;

public:
	virtual void process() = 0;
	virtual void prepare() = 0;
	virtual void reset() = 0;
};

