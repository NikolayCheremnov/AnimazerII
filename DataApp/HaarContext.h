#pragma once
#include "FrameProcessorContext.h"

#include <opencv2/core/types.hpp>

using namespace cv;

class HaarContext :
    public FrameProcessorContext
{
private:
	// context fields
	Scalar* rect_color;
	Point* rect_p1;
	Point* rect_p2;
	string rect_str;
	string header;
	string path;
	int mode;

public:
    HaarContext(string ID, LoggerI* lg);
	~HaarContext();

	// context methods
	void reset_context();

	// common context setters
	void set_context_1(string header, Point rect_p1, Point rect_p2, Scalar rect_color, string rect_text, int mode);
	void set_context_2(string header, Scalar rect_color, string rect_text, string path, int mode);
	void set_context_3(string header, Scalar rect_color, string rect_text, int mode);

	// getters
	Point* get_rect(string arg);
	Scalar* get_rect_color() { return rect_color; }
	string get_rect_str() { return rect_str; }
	string get_header() { return header; }
	string get_path() { return path; }
	int get_mode() { return mode; }

	// setters
	void set_mode(int mode) { this->mode = mode; }
};

