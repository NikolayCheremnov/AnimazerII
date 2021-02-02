#pragma once
#include <string>

using namespace std;

class ImageObj
{
protected:
	string ID;

public:
	ImageObj(string ID) { this->ID; }
	virtual ~ImageObj() {}

	virtual void init(string path) = 0;
	virtual void show(string s_args) = 0;
};

