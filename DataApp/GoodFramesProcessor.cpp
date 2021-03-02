#include "GoodFramesProcessor.h"

GoodFramesProcessor::GoodFramesProcessor(string ID, LoggerI* lg) : FrameProcessorI(ID, lg)
{
}

void GoodFramesProcessor::process(Mat frame, FrameProcessorContext* super_context)
{
	HaarContext* context = (HaarContext*)super_context;
	imwrite(context->get_path() + "\\Good\\" + to_string(context->get_mode()) + ".bmp", frame);
	Point* p1_rect = context->get_rect("p1");
	Point* p2_rect = context->get_rect("p2");
	Scalar* rect_color = context->get_rect_color();
	if (p1_rect == nullptr || p2_rect == nullptr || rect_color == nullptr) {
		if (lg != nullptr)
			lg->log(2, "GoodFramesProcessor:process:" + ID + ":" + "bad context" + ":");
		throw new exception("bad context");
	}
	rectangle(frame, *p1_rect, *p2_rect, *rect_color, 4);
	putText(frame, 
		to_string(context->get_mode()) + " " + context->get_rect_str(), 
		Point(p1_rect->x, p2_rect->y + 50), FONT_HERSHEY_DUPLEX, 0.5, *rect_color, 2);
	imshow(context->get_rect_str(), frame);
	char reply = waitKey(1);
	if (reply == 32) {
		destroyWindow(context->get_rect_str());
		context->set_mode(-2);
	}
}