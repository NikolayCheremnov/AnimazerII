#pragma once
#include "OnOffMatFrameSourceI.h"
#include "MatFrameSourceI.h"
#include "WebCamSource.h"

class MatFrameSourceAdapter :
    public OnOffMatFrameSourceI
{
private:
    MatFrameSourceI* frame_source;
    string source_name = source_name;
    
public:
    MatFrameSourceAdapter(string ID, LoggerI* lg, string source_name);
    ~MatFrameSourceAdapter();

    Mat get_frame();
    void turn_on();
    void turn_off();
};

