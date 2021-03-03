#include "HaarContext.h"

HaarContext::HaarContext(string ID, LoggerI* lg) : FrameProcessorContext(ID, lg)
{
	reset_context();
}

HaarContext::~HaarContext()
{
	reset_context();
}

void HaarContext::reset_context()
{
	if (rect_p1 != nullptr) {
		delete rect_p1;
		rect_p1 = nullptr;
	}
	if (rect_p2 != nullptr) {
		delete rect_p2;
		rect_p2 = nullptr;
	}
	rect_str = "";
	header = "";
	path = "";
	mode = -1;
	good_size = 0;
	bad_size = 0;
}

void HaarContext::set_context_with_rect(string header, Point rect_p1, Point rect_p2, string rect_text, int mode)
{
	this->header = header;
	this->rect_p1 = new Point(rect_p1);
	this->rect_p2 = new Point(rect_p2);
	this->rect_str = rect_text;
	this->mode = mode;
}

void HaarContext::set_context(string header, string rect_text, string path, int mode)
{
	this->header = header;
	this->rect_str = rect_text;
	this->path = path;
	this->mode = mode;
}

Point* HaarContext::get_rect(string arg)
{
	if (arg == "p1")
		return rect_p1;
	else if (arg == "p2")
		return rect_p2;
	else
		return nullptr;
}
