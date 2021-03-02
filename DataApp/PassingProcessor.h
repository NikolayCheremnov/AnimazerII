#pragma once
#include "FrameProcessorI.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class PassingProcessor :
    public FrameProcessorI
{
public:
    PassingProcessor(string ID, LoggerI* lg);

    void process(Mat frame, FrameProcessorContext* super_context);
};

