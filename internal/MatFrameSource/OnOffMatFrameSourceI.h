#pragma once
#include <string>
#include <opencv2/core/mat.hpp>
#include "../api/LoggerI.h"

using namespace std;
using namespace cv;

class OnOffMatFrameSourceI
{
protected:
	string ID;
	LoggerI* lg;

public:
	OnOffMatFrameSourceI(string ID, LoggerI* lg);
	virtual ~OnOffMatFrameSourceI() {}

	virtual Mat get_frame() = 0;
	virtual void turn_on() = 0;
	virtual void turn_off() = 0;
};

