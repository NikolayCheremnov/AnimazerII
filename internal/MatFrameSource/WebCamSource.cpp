#include "WebCamSource.h"

WebCamSource::WebCamSource(string ID, LoggerI* lg, int device_index) : MatFrameSourceI(ID, lg)
{
	this->device_index = device_index;
	camera = new VideoCapture(device_index);
	if (!camera->isOpened()) {
		if (lg != nullptr)
			lg->log(2, "WebCamSource:WebCamSource:" + ID + ":device " + to_string(device_index) + " is not accessible:");
		throw exception("device is not accessible:");
	}
}

WebCamSource::~WebCamSource()
{
	delete camera;
}

Mat WebCamSource::get_frame()
{
	Mat frame;
	camera->read(frame);
	return frame;
}
