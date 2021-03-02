#include "FrameProcessorContext.h"

FrameProcessorContext::FrameProcessorContext(string ID, LoggerI* lg)
{
	this->ID = ID;
	this->lg = lg;
	if (lg != nullptr)
		lg->log(1, "mediator:FrameProcessorContext:FrameProcessorContext:" + ID +
			":context-mediator setted between HaarClassifierManager and FrameProcessorI:");
}

