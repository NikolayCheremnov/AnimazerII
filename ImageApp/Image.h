#pragma once
#include <string>

#include "ImageObj.h"

class Image
{
private:
	std::string ID;
	ImageObj* img;

public:
	Image(std::string ID) { this->ID = ID; }
	virtual ~Image() {};
};

