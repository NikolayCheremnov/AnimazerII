#include "HaarClassifierCreator.h"

HaarClassifierCreator::HaarClassifierCreator(string ID, LoggerI* lg) : DataSetPacker(ID, lg)
{
	
}

void HaarClassifierCreator::DatasetPack(FrameProcessorContext* super_context, string config_file)
{
	HaarContext* context = (HaarContext*)super_context;
	if (lg != nullptr)
		lg->log(3, "haar classifier creating started");
	// initialization by context and configs
	working_path = context->get_path();
	Point p1 = Point(*context->get_rect("p1"));
	Point p2 = Point(*context->get_rect("p2"));
	map<string, string> params = FileSystemManager::read_file_to_map_params(config_file);
	
	// processing
	if (lg != nullptr)
		lg->log(3, "bad dat file writing");
	write_bad_dat_file();
	if (lg != nullptr)
		lg->log(3, "good dat file writing");
	write_good_dat_file(p1, p2);
	if (lg != nullptr)
		lg->log(3, "good normalization");
	good_normalization(params["opencv_createsamples_util_path"], params["dst_path"],
		params["dst_name"], params["width"], params["height"]);
	if (lg != nullptr)
		lg->log(3, "classifier training");
	training(params["traincascade_util_path"], params["dst_path"], params["normal_srs"],
		params["cascade_levels"], params["quality_k"], params["false_k"], params["good_count"], 
		params["bad_count"], params["width"], params["height"], params["allocated_memory"]);
}

void HaarClassifierCreator::write_bad_dat_file()
{
	list<string> bad_files = FileSystemManager::getAllDirFiles(working_path + "\\Bad");
	ofstream out;
	out.open(working_path + "\\Bad.dat");	// TODO: add try/catch
	for (string fname: bad_files)
		out << "Bad\\" + fname << endl;
	out.close();
}

void HaarClassifierCreator::write_good_dat_file(Point p1, Point p2)
{
	list<string> good_files = FileSystemManager::getAllDirFiles(working_path + "\\Bad");
	ofstream out;
	out.open(working_path + "\\Good.dat");	// TODO: add try/catch
	for (string fname : good_files)
		out << "Good\\" + fname << " 1 " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
	out.close();
}

void HaarClassifierCreator::good_normalization(string opencv_createsamples_util_path, string dst_path, string dst_name, string width, string height)
{	
	string cmd = opencv_createsamples_util_path + " -info " +
		working_path + "\\Good.dat -vec " + dst_path + "\\" +
		dst_name + "_samples.vec -w " + width + " -h " + height;
	system(cmd.c_str());
}

void HaarClassifierCreator::training(string traincascade_util_path, string dst_path, string normal_srs, string cascade_levels, string quality_k, string false_k, string good_count, string bad_count, string width, string height, string allocated_memory)
{
	string cmd = traincascade_util_path + " -data " + dst_path + " -vec " + normal_srs +
		" -bg " + working_path + "\\Bad.dat -numStages " + cascade_levels + " -minhitrate " + quality_k +
		" -maxFalseAlarmRate " + false_k + " -numPos " + good_count + " -numNeg " + bad_count +
		" -w " + width + " -h " + height + " -mode ALL -precalcValBufSize " +
		allocated_memory + " -precalcIdxBufSize " + allocated_memory;
	system(cmd.c_str());
}

