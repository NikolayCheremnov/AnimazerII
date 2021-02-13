#pragma once
#include "Image.h"

using namespace std;

class SingleImage :
    public Image
{
private:
    string path;

public:
    SingleImage(string ID, LoggerI* lg) : Image(ID, lg) {}
    ~SingleImage() {}
    void set_path(string path) { this->path = path; }
    void PerformImageLoad();
    void Show();
};

