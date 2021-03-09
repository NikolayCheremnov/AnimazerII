#pragma once
#include "Image.h"
class StatusImageI :
    public Image
{
protected:
    Image* image;

public:
    StatusImageI(string ID, LoggerI* lg, Image* image);
    virtual ~StatusImageI() {}
    
    void SetImageObj(ImageObj* img);
    ImageObj* getImageObj() { return image->getImageObj(); }

    virtual void set_path(string path) = 0;
    virtual void PerformImageLoad() = 0;
    virtual void ReleaseImage() = 0;
    virtual void Show() = 0;
    virtual Image* clone() = 0;

    virtual string GetInfoStr() = 0;
    virtual void SetInfo(string i_args) = 0;
};

