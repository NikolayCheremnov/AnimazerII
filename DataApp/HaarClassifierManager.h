#pragma once

#include "DataManagerI.h"
#include "FrameProcessorI.h"
#include "Calibrator.h"
#include "GoodFramesProcessor.h"
#include "RoughCalibrator.h"
#include "BadFramesProcessor.h"
#include "HaarContext.h"

#include "../internal/FileSystemManager/FileSystemManager.h"
#include "../internal/MatFrameSource/MatFrameSourceI.h"

class HaarClassifierManager :
    public DataManagerI
{
private:
    string working_path;
    MatFrameSourceI* frame_source;

public:
    HaarClassifierManager(string ID, LoggerI* lg, string working_path, MatFrameSourceI* frame_source);
    ~HaarClassifierManager();

    FrameProcessorContext* DatasetCreating(int good_set_size, int bad_set_size);
    void DatasetPack(DataSetPacker* packer, FrameProcessorContext* context, string args);
};

