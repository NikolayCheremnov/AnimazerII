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
	}
	catch (Exception ex) {
		// write exception log here
	}
}

void MatImage::show(string s_args)
{
	imshow(s_args, *img);
	waitKey(0);
}
