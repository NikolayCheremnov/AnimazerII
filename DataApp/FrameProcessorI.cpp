#include "FrameProcessorI.h"

FrameProcessorI::FrameProcessorI(string ID, LoggerI* lg)
{
	this->ID = ID;
	this->lg = lg;
	if (lg != nullptr)
		lg->log(1, "strategy:FrameProcessorI:FrameProcessorI:" + ID +
			":FrameProcessor strategy"+ ID +"created:");
}
