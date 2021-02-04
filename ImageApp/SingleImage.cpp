#include "SingleImage.h"

void SingleImage::PerformImageLoad()
{
	if (img != nullptr) {
		img->init(path);
		img->show(ID);
		if (lg != nullptr) {
			lg->log(1, "bridge:SingleImage&ImageObj:PerformImageLoad:" + ID + "&" + img->getID() +
				":Bridge is used between 'Image' object " + ID + "and 'ImageObj' object " + img->getID() + ":");
			lg->log(3, "image loaded into RAM");
		}
	}
	else
		lg->log(3, "can`t perform image loading because the 'img' object is not initialized");
}
