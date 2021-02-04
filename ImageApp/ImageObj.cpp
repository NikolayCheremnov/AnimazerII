#include "ImageObj.h"

ImageObj::ImageObj(string ID, LoggerI* lg)
{
	this->ID = ID;
	this->lg = lg;
	if (lg != nullptr)
		lg->log(3, "'ImageObj' object " + ID + " was created");
}

ImageObj::~ImageObj() 
{
	if (lg != nullptr)
		lg->log(3, "'ImageObj' object " + ID + " was deleted");
}
