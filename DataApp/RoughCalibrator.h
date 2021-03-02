#pragma once
#include "FrameProcessorI.h"
#include "HaarContext.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class RoughCalibrator :
    public FrameProcessorI
{
public:
    RoughCalibrator(string ID, LoggerI* lg);

    void process(Mat frame, FrameProcessorContext* super_context);
};

