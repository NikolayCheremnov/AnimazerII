#pragma once

#include <string>

#include "../internal/api/LoggerI.h"
#include "FrameProcessorContext.h"
#include "DataSetPacker.h"

using namespace std;

class DataManagerI
{
protected:
	string ID;
	LoggerI* lg;

public:
	DataManagerI(string ID, LoggerI* lg);
	virtual ~DataManagerI() {};
	
	virtual FrameProcessorContext* DatasetCreating(int good_set_size, int bad_set_size) = 0;
	virtual void DatasetPack(DataSetPacker* packer, FrameProcessorContext* context, string args) = 0;
};

