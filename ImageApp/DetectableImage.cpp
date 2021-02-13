#include "DetectableImage.h"

DetectableImage::DetectableImage(string ID, LoggerI* lg, Image* image, string info): StatusImageI(ID, lg, image)
{
	SetInfo(info);
}

void DetectableImage::set_path(string path)
{
	image->set_path(path);
}

void DetectableImage::PerformImageLoad()
{
	image->PerformImageLoad();
}

void DetectableImage::Show()
{
	image->Show();
}

string DetectableImage::GetInfoStr()
{
	switch (status) {
	case Status::UNDEFINED:
		return "UNDEFINED";
	case Status::POSITIVE:
		return "POSITIVE";
	case Status::NEGATIVE:
		return "NEGATIVE";
	}
}

void DetectableImage::SetInfo(string i_args)
{
	if (i_args == "POSITIVE" || i_args == "positive" || i_args == "TRUE" || i_args == "true")
		status = Status::POSITIVE;
	else if (i_args == "NEGATIVE" || i_args == "negative" || i_args == "FALSE" || i_args == "false")
		status = Status::NEGATIVE;
	else
		status = Status::UNDEFINED;
	if (lg != nullptr)
		lg->log(3, "'DetectableImage' object " + ID + " get " + GetInfoStr() + " status");
}
