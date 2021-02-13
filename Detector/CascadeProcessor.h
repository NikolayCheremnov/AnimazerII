#pragma once
#include "ProcessorI.h"
#include <opencv2/objdetect.hpp>

#include "../ImageApp/MatImage.h"
#include "../ImageApp/StatusImageI.h"

using namespace cv;

class CascadeProcessor :
    public ProcessorI
{
private:
    bool isReady;
    CascadeClassifier* Classifier;
    string path;

public:
    CascadeProcessor(string ID, LoggerI* lg);
    ~CascadeProcessor();

    void set_path(string path);

    void prepare();
    void process(Image* processed);

};

