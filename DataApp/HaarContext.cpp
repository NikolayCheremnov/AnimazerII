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

void HaarContext::SaveContext(string path)
{
	ofstream out(path);
	if (out.is_open()) {
		out << "rect_p1:";
		if (rect_p1 == nullptr)
			out << "nullptr" << endl;
		else {
			out << endl << "rect_p1_x:" << rect_p1->x << endl;
			out << "rect_p1_y:" << rect_p1->y << endl;
		}
		out << "rect_p2:";
		if (rect_p2 == nullptr)
			out << "nullptr" << endl;
		else {
			out << endl << "rect_p2_x:" << rect_p2->x << endl;
			out << "rect_p2_y:" << rect_p2->y << endl;
		}
		out << "rect_str:" << rect_str << endl;
		out << "header:" << header << endl;
		out << "path:" << this->path << endl;
		out << "mode:" << mode << endl;
		out << "good_size:" << good_size << endl;
		out << "bad_size:" << bad_size;
		out.close();
	}
	else
		throw exception("can`t create file for context saving");
}

void HaarContext::LoadContext(string path)
{
	reset_context();
	try {
		map<string, string> params = FileSystemManager::read_file_to_map_params(path);
		if (params["rect_p1"] == "nullptr")
			rect_p1 = nullptr;
		else {
			rect_p1 = new Point();
			rect_p1->x = stoi(params["rect_p1_x"]);
			rect_p1->y = stoi(params["rect_p1_y"]);
		}
		if (params["rect_p2"] == "nullptr")
			rect_p2 = nullptr;
		else {
			rect_p2 = new Point();
			rect_p2->x = stoi(params["rect_p2_x"]);
			rect_p2->y = stoi(params["rect_p2_y"]);
		}
		rect_str = params["rect_str"];
		header = params["header"];
		this->path = params["path"];
		mode = stoi(params["mode"]);
		this->good_size = stoi(params["good_size"]);
		this->bad_size = stoi(params["bad_size"]);
	}
	catch (exception ex) {
		if (lg != nullptr)
			lg->log(3, "bad context file");
		throw ex;
	}
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
