#pragma once
#include "ImageObj.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class MatImage :
    public ImageObj
{
private:
    Mat* img;

public:
    MatImage(string ID): ImageObj(ID) {
        img = nullptr;
    }
    ~MatImage() {
        Release();
    }
    
    void Release();
    void init(string path);
    void show(string s_args);
};

