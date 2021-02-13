#pragma once
#include <string>
#include "../internal/api/LoggerI.h"

using namespace std;

class ImageObj
{
protected:
	string ID;
	LoggerI* lg;

public:
	ImageObj(string ID, LoggerI* lg);
	virtual ~ImageObj();

	string getID() { return ID; }
	virtual void init(string path) = 0;
	virtual void show(string s_args) = 0;

};

