#pragma once
#include "FrameProcessorI.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class Calibrator :
    public FrameProcessorI
{
public:
    Calibrator(string ID, LoggerI* lg);

    void process(Mat frame, FrameProcessorContext* super_context);
};

