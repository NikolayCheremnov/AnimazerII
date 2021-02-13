#pragma once

#include <string>
#include "../internal/api/LoggerI.h"
#include "../ImageApp/Image.h"

using namespace std;

class ProcessorI
{
protected:
	string ID;
	LoggerI* lg;

public:
	ProcessorI(string ID, LoggerI* lg);
	virtual ~ProcessorI() {}

	virtual void prepare() = 0;
	virtual void process(Image* processed) = 0;
};

