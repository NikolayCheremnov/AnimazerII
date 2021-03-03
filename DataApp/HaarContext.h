#pragma once
#include "FrameProcessorContext.h"

#include <opencv2/core/types.hpp>

using namespace cv;

class HaarContext :
    public FrameProcessorContext
{
private:
	// context fields
	Point* rect_p1;
	Point* rect_p2;
	string rect_str;
	string header;
	string path;
	int mode;
	int good_size;
	int bad_size;

public:
    HaarContext(string ID, LoggerI* lg);
	~HaarContext();

	// context methods
	void reset_context();

	// common context setters
	void set_context_with_rect(string header, Point rect_p1, Point rect_p2, string rect_text, int mode);
	void set_context(string header, string rect_text, string path, int mode);

	// getters
	Point* get_rect(string arg);
	string get_rect_str() { return rect_str; }
	string get_header() { return header; }
	string get_path() { return path; }
	int get_mode() { return mode; }
	int get_good() { return good_size; }
	int get_bad() { return bad_size; }

	// setters
	void set_mode(int mode) { this->mode = mode; }

	// increments
	void good_inc() { good_size++; }
	void bad_inc() { bad_size++; }
};

