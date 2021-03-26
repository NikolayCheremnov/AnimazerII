#include "SingleImage.h"

SingleImage::~SingleImage()
{
	ReleaseImage();
}

void SingleImage::PerformImageLoad()
{
	if (img != nullptr) {
		img->init(path);
		if (lg != nullptr) {
			lg->log(1, "bridge:SingleImage&ImageObj:PerformImageLoad:" + ID + "&" + img->getID() +
				":Bridge is used between 'Image' object " + ID + "and 'ImageObj' object " + img->getID() + ":");
			lg->log(3, "image loaded into RAM");
		}
	}
	else
		if (lg != nullptr)
			lg->log(3, "can`t perform image loading because the 'img' object is not initialized");
}

void SingleImage::ReleaseImage()
{
	if (img != nullptr) {
		delete img;
		img = nullptr;
	}
}

void SingleImage::Show()
{
	if (img != nullptr)
		img->show(ID);
}

Image* SingleImage::clone()
{
	SingleImage* clone = new SingleImage(ID + "_clone", lg);
	clone->path = path;
	if (img == nullptr)
		clone->img = nullptr;
	else
		clone->PerformImageLoad();
	if (lg != nullptr)
		lg->log(1, "prototype:SingleImage:clone:" + ID + ":object was clone by prototype:");
	return clone;
}
