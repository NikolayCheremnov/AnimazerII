#include "Image.h"

Image::Image(string ID, LoggerI* lg)
{
	this->ID = ID;
	this->img = nullptr;
	this->lg = lg;
	if (lg != nullptr)
		lg->log(3, "'Image' object " + ID + " was created");
}

Image::~Image()
{
	if (img != nullptr)
		delete img;
	if (lg != nullptr)
		lg->log(3, "'Image' object " + ID + " was deleted");
}

void Image::SetImageObj(ImageObj* img)
{
	try {
		this->img = img;
		if (lg != nullptr)
			lg->log(1, "bridge:Image&ImageObj:SetImageObj:" + ID + "&" + img->getID() +
				":Bridge is stretched between 'Image' object " + ID + "and 'ImageObj' object " + img->getID() + ":");
	}
	// class:method:obj_id:error_msg
	catch (exception ex) {
		if (lg != nullptr)
			lg->log(2, "Image:SetImageObj:" + ID + ":" + ex.what() + ":");
		throw ex;
	}
}
