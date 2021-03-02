#pragma once

#include <string>
#include "../api/LoggerI.h"
#include <opencv2/core/mat.hpp>

using namespace std;
using namespace cv;

class MatFrameSourceI
{
private:
	string ID;
	LoggerI* lg;

public:
	MatFrameSourceI(string ID, LoggerI* lg);
	virtual ~MatFrameSourceI() {};

	virtual Mat get_frame() = 0;
};

