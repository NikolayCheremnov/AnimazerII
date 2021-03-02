#pragma once
#include <string>
#include <fstream>
#include "../internal/api/LoggerI.h"
#include "FrameProcessorContext.h"

using namespace std;

class DataSetPacker
{
protected:
	string ID;
	LoggerI* lg;

public:
	DataSetPacker(string ID, LoggerI* lg);
	~DataSetPacker(){}

	virtual void DatasetPack(FrameProcessorContext* super_context, string args) = 0;
};

