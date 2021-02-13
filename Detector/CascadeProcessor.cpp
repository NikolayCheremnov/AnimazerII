#include "CascadeProcessor.h"
#include <opencv2/imgproc.hpp>

CascadeProcessor::CascadeProcessor(string ID, LoggerI* lg) : ProcessorI(ID, lg)
{
	Classifier = new CascadeClassifier();
	isReady = false;
}

CascadeProcessor::~CascadeProcessor()
{
	delete Classifier;
}

void CascadeProcessor::set_path(string path)
{
	this->path = path;
	if (lg != nullptr)
		lg->log(3, "'CascadeProcessor' object " + ID + " get XML path " + path);
}

void CascadeProcessor::prepare()
{
	try {
		Classifier->load(path);
		if (Classifier->empty())
			throw exception("XML file not loaded");
		isReady = true;
	}
	catch (exception ex) {
		if (lg != nullptr)
			lg->log(2, "CascadeProcessor:prepare:" + ID + ":" + ex.what() + ":");
		isReady = false;
	}
}

void CascadeProcessor::process(Image* srs)
{
	StatusImageI* processed = (StatusImageI*)srs;	// TODO: сделать копирование любого объекта Image с приведением в StatusImage (иначе может вылезти error)
	if (!isReady) {
		if (lg != nullptr)
			lg->log(3, "'CascadeProcessor' object " + ID + " not ready for processing");
		return;
	}
	Mat* img = ((MatImage*)processed->getImageObj())->getMatImg();
	vector<Rect> matches;
	Classifier->detectMultiScale(*img, matches, 1.1, 10);	// TODO: set good params
	if (matches.size() > 0) {
		processed->SetInfo("true");
		for (int i = 0; i < matches.size(); i++)
			rectangle(*img, matches[i].tl(), matches[i].br(), Scalar(255, 0, 255), 3);
	}
	else
		processed->SetInfo("false");

	if (lg != nullptr)
		lg->log(3, ID + " image processed");
}
