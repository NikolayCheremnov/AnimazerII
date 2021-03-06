#include "MatFrameSourceAdapter.h"

MatFrameSourceAdapter::MatFrameSourceAdapter(string ID, LoggerI* lg, string source_name) : OnOffMatFrameSourceI(ID, lg)
{
	this->source_name = source_name;
	frame_source = nullptr;
	if (lg != nullptr)
		lg->log(1, "adapter:MatFrameSourceAdapter:MatFrameSourceAdapter:" + ID +
			":MatFrameSourceAdapter for on off" + ID + "created:");
}

MatFrameSourceAdapter::~MatFrameSourceAdapter()
{
	if (frame_source != nullptr)
		delete frame_source;
}

Mat MatFrameSourceAdapter::get_frame()
{
	if (frame_source != nullptr)
		return frame_source->get_frame();
	else
		throw exception("try to user non turn on frame source");
}

void MatFrameSourceAdapter::turn_on()
{
	if (frame_source == nullptr)
		if (source_name == "WebCamSource")
			frame_source = new WebCamSource(ID + "_wcs", lg, 0);
}

void MatFrameSourceAdapter::turn_off()
{
	if (frame_source != nullptr) {
		delete frame_source;
		frame_source = nullptr;
	}
}
