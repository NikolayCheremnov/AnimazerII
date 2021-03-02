#pragma once

#include <string>

#include "../internal/api/LoggerI.h"

using namespace std;

class FrameProcessorContext
{
protected:
	string ID;
	LoggerI* lg;

public:
	FrameProcessorContext(string ID, LoggerI* lg);
	virtual ~FrameProcessorContext() {};
};

