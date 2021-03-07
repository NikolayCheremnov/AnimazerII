#pragma once
#include <string>
#include <map>

#include "../internal/api/LoggerI.h"
#include "DataManagerI.h"
#include "FrameProcessorContext.h"
#include "DataSetPacker.h"
#include "../internal/MatFrameSource/OnOffMatFrameSourceI.h"

using namespace std;

class DataAppFactoryI
{
protected:
	string ID;
	LoggerI* lg;

public:
	DataAppFactoryI(string ID, LoggerI* lg);
	virtual ~DataAppFactoryI() {}

	virtual OnOffMatFrameSourceI* create_on_off_frame_source(string ID, LoggerI* lg, map<string, string> args) = 0;
	virtual DataManagerI* create_data_manager(string ID, LoggerI* lg, map<string, string> args) = 0;
	virtual FrameProcessorContext* create_context(string ID, LoggerI* lg, map<string, string> args) = 0;
	virtual DataSetPacker* create_data_set_packer(string ID, LoggerI* lg, map<string, string> args) = 0;
};

