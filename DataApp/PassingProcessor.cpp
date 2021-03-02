#include "PassingProcessor.h"

PassingProcessor::PassingProcessor(string ID, LoggerI* lg) : FrameProcessorI(ID, lg)
{
}

void PassingProcessor::process(Mat frame, FrameProcessorContext* super_context)
{
	throw exception("passing proccesor is not done yet");
}
