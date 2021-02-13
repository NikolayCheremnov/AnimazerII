#include "MatImage.h"

void MatImage::Release()
{
	delete img;
	img = nullptr;
}

void MatImage::init(string path)
{
	try {
		img = new Mat();
		*img = imread(path);
		if (lg != nullptr) 
			lg->log(3, "'MatImage' object " + ID + " was initialize");
	}
	catch (Exception ex) {
		if (lg != nullptr)
			lg->log(2, "MatImage:init:" + ID + ":" + ex.what() + ":");
		throw ex;
	}
}

void MatImage::show(string s_args)
{
	try {
		imshow(s_args, *img);
		waitKey(0);
	}
	catch (Exception ex) {
		if (lg != nullptr)
			lg->log(2, "MatImage:show:" + ID + ":" + ex.what() + ":");
		throw ex;
	}
}
