#include "HaarClassifierManager.h"

void HaarClassifierManager::remove_old_good_and_bad_dirs()
{
	if (FileSystemManager::verify_existence(working_path + "\\Good")) {
		if (lg != nullptr)
			lg->log(3, "good directory exists yet, it will be deleted with all files");
		FileSystemManager::delete_dir_with_all_files(working_path + "\\Good");
	}
	if (FileSystemManager::verify_existence(working_path + "\\Bad")) {
		if (lg != nullptr)
			lg->log(3, "bad directory exists yet, it will be deleted with all files");
		FileSystemManager::delete_dir_with_all_files(working_path + "\\Bad");
	}
}

void HaarClassifierManager::processing_loop(HaarContext* context, FrameProcessorI* frame_processor)
{
	FrameProcessorI* current_processor = frame_processor;
	while (context->get_mode() != -1) {
		Mat next_frame = frame_source->get_frame();
		current_processor->process(next_frame, context);
		if (context->get_mode() == -2) // pause
			current_processor = new PassingProcessor("pause", lg);
		else if (context->get_mode() == -3) {
			delete current_processor;
			current_processor = frame_processor;
			context->set_mode(0);
		}
	}
}

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

FrameProcessorContext* HaarClassifierManager::DatasetCreating()
{
	// preparing directories for bad and good pictures
	FileSystemManager::create_subdir(working_path, "Good");
	FileSystemManager::create_subdir(working_path, "Bad");

	// using objects
	HaarContext* context = new HaarContext("haar_context_used_by" + ID, lg);
	FrameProcessorI* frame_processor = nullptr;

	// 1. calibration
	context->set_context_with_rect("good_calibration", Point(200, 150), Point(500, 350), "calibration", 0);
	frame_processor = new Calibrator(ID + "_calibrator", lg);
	processing_loop(context, frame_processor);
	delete frame_processor;

	// 2. context saved, writing good files
	context->set_context("good_shooting", "leave the object inside the rect (or space for end)", working_path, 0);
	frame_processor = new GoodFramesProcessor(ID + "_good_frame_processor", lg);
	processing_loop(context, frame_processor);
	delete frame_processor;

	// 3. rough calibration for bad
	context->set_context("rough_calibration", "press SPACE for start shooting bad set", working_path, 0);
	frame_processor = new RoughCalibrator(ID + "_rought_calibrator", lg);
	processing_loop(context, frame_processor);
	delete frame_processor;

	// 4. context saved, writing bad files
	context->set_context("bad_shooting", "press space for end", working_path, 0);
	frame_processor = new BadFramesProcessor(ID + "_bad_frame_processor", lg);
	processing_loop(context, frame_processor);
	delete frame_processor;

	return context;
}

void HaarClassifierManager::DatasetPack(DataSetPacker* packer, FrameProcessorContext* context, string args)
{
	packer->DatasetPack(context, args);
}
