#include "BadFramesProcessor.h"

BadFramesProcessor::BadFramesProcessor(string ID, LoggerI* lg) : FrameProcessorI(ID, lg)
{
}

void BadFramesProcessor::process(Mat frame, FrameProcessorContext* super_context)
{
	HaarContext* context = (HaarContext*)super_context;
	imwrite(context->get_path() + "\\Bad\\" + to_string(context->get_bad()) + ".bmp", frame);
	Point* p1_rect = context->get_rect("p1");
	Point* p2_rect = context->get_rect("p2");
	if (p1_rect == nullptr || p2_rect == nullptr) {
		if (lg != nullptr)
			lg->log(2, "BadFramesProcessor:process:" + ID + ":" + "bad context" + ":");
		throw new exception("bad context");
	}
	putText(frame,
		to_string(context->get_bad()) + " " + context->get_rect_str(),
		Point(p1_rect->x, p2_rect->y + 50), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 0, 255), 2);
	context->bad_inc();
	imshow(context->get_rect_str(), frame);
	char reply = waitKey(1);
	if (reply == 32) {
		destroyWindow(context->get_rect_str());
		context->set_mode(-1);
	}
	else if (reply == 'p') {
		destroyWindow(context->get_rect_str());
		context->set_mode(-2);
	}
}
