#include "PassingProcessor.h"

PassingProcessor::PassingProcessor(string ID, LoggerI* lg) : FrameProcessorI(ID, lg)
{

}

void PassingProcessor::process(Mat frame, FrameProcessorContext* super_context)
{
	HaarContext* context = (HaarContext*)super_context;
	Point* p1_rect = context->get_rect("p1");
	Point* p2_rect = context->get_rect("p2");
	if (p1_rect == nullptr || p2_rect == nullptr) {
		if (lg != nullptr)
			lg->log(2, "PassingProcessor:process:" + ID + ":" + "bad context" + ":");
		throw new exception("bad context");
	}
	putText(frame, "press p for play", Point(p1_rect->x, p2_rect->y + 50), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 255, 255), 2);
	imshow("pause", frame);
	char reply = waitKey(1);
	if (reply == 'p') {
		destroyWindow("pause");
		context->set_mode(-3);
	}
}
