#pragma once
#include <string>
#include "../internal/api/LoggerI.h"
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

class WebCamShooter
{
private:
	string ID;
	LoggerI* lg;

	VideoCapture* camera;
	int device_index;
	Point p1_rect;
	Point p2_rect;
	Scalar rect_color;
	string rect_str;

public:
	WebCamShooter(string ID, LoggerI* lg);
	~WebCamShooter();

	void set_object_rect(Point p1, Point p2);
	void shoot_frames(string path, int count);
	Mat capture();
};

