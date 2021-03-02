#include "HaarClassifierManager.h"

HaarClassifierManager::HaarClassifierManager(string ID, LoggerI* lg, string working_path, MatFrameSourceI* frame_source) : DataManagerI(ID, lg)
{
	if (!FileSystemManager::verify_existence(working_path))
		throw exception("Bad working_path for haar");
	this->working_path = working_path;
	if (lg != nullptr)
		lg->log(1, "facade:HaarClassifierManager:HaarClassifierManager:" + ID + ":Facade setted:");
	this->frame_source = frame_source;
}

HaarClassifierManager::~HaarClassifierManager()
{
	delete frame_source;
}

FrameProcessorContext* HaarClassifierManager::DatasetCreating(int good_set_size, int bad_set_size)
{
	// preparing directories for bad and good pictures
	FileSystemManager::create_subdir(working_path, "Good");
	FileSystemManager::create_subdir(working_path, "Bad");

	// using objects
	HaarContext* context = new HaarContext("haar_context_used_by" + ID, lg);
	FrameProcessorI* frame_processor = nullptr;

	// 1. calibration
	context->set_context_1("good_calibration", Point(200, 150), Point(500, 350), Scalar(0, 255, 0), "calibration", 1);
	frame_processor = new Calibrator(ID + "_calibrator", lg);
	while (context->get_mode() != -1) {
		Mat next_frame = frame_source->get_frame();
		frame_processor->process(next_frame, context);
	}
	delete frame_processor;

	// 2. context saved, writing good files
	context->set_context_2("good_shooting", Scalar(0, 0, 255), "leave the object inside the rect (or space for end)", working_path, 0);
	frame_processor = new GoodFramesProcessor(ID + "_good_frame_processor", lg);
	for (; context->get_mode() < good_set_size && context->get_mode() != -1; context->set_mode(context->get_mode()+1)) {
		Mat next_frame = frame_source->get_frame();
		frame_processor->process(next_frame, context);
	}
	delete frame_processor;

	// 3. rough calibration for bad
	context->set_context_3(ID + "rough_calibration", Scalar(0, 255, 0), "press SPACE for start shooting bad set", 1);
	frame_processor = new RoughCalibrator(ID + "_rought_calibrator", lg);
	while (context->get_mode() != -1) {
		Mat next_frame = frame_source->get_frame();
		frame_processor->process(next_frame, context);
	}
	delete frame_processor;

	// 4. context saved, writing bad files
	context->set_context_2("bad_shooting", Scalar(0, 0, 255), "press space for end", working_path, 0);
	frame_processor = new BadFramesProcessor(ID + "_bad_frame_processor", lg);
	for (; context->get_mode() < bad_set_size && context->get_mode() != -1; context->set_mode(context->get_mode() + 1)) {
		Mat next_frame = frame_source->get_frame();
		frame_processor->process(next_frame, context);
	}
	delete frame_processor;

	return context;
}

void HaarClassifierManager::DatasetPack(DataSetPacker* packer, FrameProcessorContext* context, string args)
{
	packer->DatasetPack(context, args);
}
