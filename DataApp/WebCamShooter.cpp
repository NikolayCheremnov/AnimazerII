#include "WebCamShooter.h"

WebCamShooter::WebCamShooter(string ID, LoggerI* lg)
{
	this->ID = ID;
	this->lg = lg;
	device_index = 0;
	camera = new VideoCapture(device_index);
	if (!camera->isOpened()) {
		if (lg != nullptr)
			lg->log(2, "WebCamShooter:WebCamShooter:" + ID + ":device " + to_string(device_index) + " is not accessible:");
		throw exception("device is not accessible:");
	}
}

WebCamShooter::~WebCamShooter()
{
	delete camera;
}

void WebCamShooter::set_object_rect(Point p1, Point p2)
{
	double width = camera->get(3);
	double height = camera->get(4);
	if (p1.x >= 0 && p1.x <= width && p1.y >= 0 && p1.y <= height &&
		p2.x >= 0 && p2.x <= width && p2.y >= 0 && p2.y <= height) {
		p1_rect = p1;
		p2_rect = p2;
	}
	else {
		if (lg != nullptr)
			lg->log(2, "WebCamShooter:set_object_rect:" + ID + ":incorrect 'object rect' params:");
		throw exception("incorrect 'object rect' params:");
	}
}

void WebCamShooter::shoot_frames(string path, int count)
{
	rect_color = Scalar(0, 255, 0);
	rect_str = "place the object inside the frame. press the SPACE to start shooting";
	Mat frame;
	while (true) {
		frame = capture();
		imshow("Preparing", frame);
		if (waitKey(10) == 32) {
			destroyWindow("Preparing");
			break;
		}
	}

	rect_color = Scalar(0, 0, 255, 0);

	for (int i = 0; i < count; i++) {
		rect_str = to_string(i) + "\\" + to_string(count) + ": leave the object inside the frame";
		frame = capture();
		imshow("capturing", frame);
		imwrite(path + "\\" + to_string(i) + ".bmp", frame);
		waitKey(1);
	}
	if (lg != nullptr)
		lg->log(3, "Shooted " + to_string(count) + " frames");
}

Mat WebCamShooter::capture()
{
	Mat frame;
	camera->read(frame);
	rectangle(frame, p1_rect, p2_rect, rect_color, 4);
	putText(frame, rect_str, Point(p1_rect.x, p2_rect.y + 50), FONT_HERSHEY_DUPLEX, 0.5, rect_color, 2);
	return frame;
}
