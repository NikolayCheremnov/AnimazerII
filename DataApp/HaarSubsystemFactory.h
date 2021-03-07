#pragma once
#include "DataAppFactoryI.h"
#include "HaarClassifierManager.h"
#include "../internal/MatFrameSource/MatFrameSourceAdapter.h"
#include "HaarContext.h"
#include "HaarClassifierCreator.h"

class HaarSubsystemFactory :
    public DataAppFactoryI
{
private:

public:
    HaarSubsystemFactory(string ID, LoggerI* lg);

    OnOffMatFrameSourceI* create_on_off_frame_source(string ID, LoggerI* lg, map<string, string> args);
    DataManagerI* create_data_manager(string ID, LoggerI* lg, map<string, string> args);
    FrameProcessorContext* create_context(string ID, LoggerI* lg, map<string, string> args);
    DataSetPacker* create_data_set_packer(string ID, LoggerI* lg, map<string, string> args);
};

