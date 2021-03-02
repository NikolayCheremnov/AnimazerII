#pragma once

#include <string>
#include <opencv2/core/mat.hpp>

#include "../internal/api/LoggerI.h"

#include "HaarContext.h"

using namespace std;
using namespace cv;

class FrameProcessorI
{
protected:
	string ID;
	LoggerI* lg;

public:
	FrameProcessorI(string ID, LoggerI* lg);
	virtual ~FrameProcessorI() {};

	virtual void process(Mat frame, FrameProcessorContext* super_context) = 0;
};

