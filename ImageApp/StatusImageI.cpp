#include "StatusImageI.h"

StatusImageI::StatusImageI(string ID, LoggerI* lg, Image* image): Image(ID, lg)
{
	if (image != nullptr) {
		this->image = image;
		if (lg != nullptr) {
			lg->log(3, "'StatusImageI' object " + ID + "was initialize with 'Image' object " + image->getID());
			lg->log(1, "decorator:StatusImageI:StatusImageI:" + ID +
				":Object + " + image->getID() + " was decorate with " + ID + ":");
		}
	}
	else {
		if (lg != nullptr)
			lg->log(2, "StatusImageI:StatusImageI:" + ID + ":" + "it is not possible to decorate (image = nullptr)" + ":");
		throw new exception("it is not possible to decorate (image = nullptr)");
	}

}

StatusImageI::~StatusImageI()
{
	if (image != nullptr)
		delete image;
}

void StatusImageI::SetImageObj(ImageObj* img)
{
	image->SetImageObj(img);
}
