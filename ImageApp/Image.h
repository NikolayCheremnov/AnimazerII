#pragma once
#include <string>

#include "ImageObj.h"
#include "../internal/api/LoggerI.h"

using namespace std;

class Image
{
protected:
	string ID;
	ImageObj* img;
	LoggerI* lg;	// if nullptr then not logging else logging

public:

	Image(string ID, LoggerI* lg);
	virtual ~Image() {};

	string getID() { return ID; }
	virtual void SetImageObj(ImageObj* img);
	virtual ImageObj* getImageObj() { return img; }

	virtual void set_path(string path) = 0;
	virtual void PerformImageLoad() = 0;
	virtual void ReleaseImage() = 0;
	virtual void Show() = 0;
	virtual Image* clone() = 0;
};

