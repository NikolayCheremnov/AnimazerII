#pragma once
#include "MatFrameSourceI.h"
#include <opencv2/videoio.hpp>
class WebCamSource :
    public MatFrameSourceI
{
private:
    VideoCapture* camera;
    int device_index;
public:
    WebCamSource(string ID, LoggerI* lg, int device_index);
    ~WebCamSource();

    Mat get_frame();
};

