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
	if (rect_color != nullptr) {
		delete rect_color;
		rect_color = nullptr;
	}
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
}

void HaarContext::set_context_1(string header, Point rect_p1, Point rect_p2, Scalar rect_color, string rect_text, int mode)
{
	this->header = header;
	this->rect_p1 = new Point(rect_p1);
	this->rect_p2 = new Point(rect_p2);
	this->rect_color = new Scalar(rect_color);
	this->rect_str = rect_text;
	this->mode = mode;
}

void HaarContext::set_context_2(string header, Scalar rect_color, string rect_text, string path, int mode)
{
	this->header = header;
	this->rect_color = new Scalar(rect_color);
	this->rect_str = rect_text;
	this->path = path;
	this->mode = mode;
}

void HaarContext::set_context_3(string header, Scalar rect_color, string rect_text, int mode)
{
	this->header = header;
	this->rect_color = new Scalar(rect_color);
	this->rect_str = rect_text;
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
