#pragma once

#include "DataManagerI.h"
#include "FrameProcessorI.h"
#include "Calibrator.h"
#include "GoodFramesProcessor.h"
#include "RoughCalibrator.h"
#include "BadFramesProcessor.h"
#include "PassingProcessor.h"
#include "HaarContext.h"
#include "../internal/FileSystemManager/FileSystemManager.h"
#include "../internal/MatFrameSource/OnOffMatFrameSourceI.h"

class HaarClassifierManager :
    public DataManagerI
{
private:
    string working_path;
    OnOffMatFrameSourceI* frame_source;
    void remove_old_good_and_bad_dirs();
    void processing_loop(HaarContext* context, FrameProcessorI* frame_processor);
public:
    HaarClassifierManager(string ID, LoggerI* lg, string working_path, OnOffMatFrameSourceI* frame_source);
    ~HaarClassifierManager();

    FrameProcessorContext* DatasetCreating();
    void DatasetPack(DataSetPacker* packer, FrameProcessorContext* context, string args);
};

