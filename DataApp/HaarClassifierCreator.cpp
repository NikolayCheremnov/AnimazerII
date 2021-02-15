#include "HaarClassifierCreator.h"

HaarClassifierCreator::HaarClassifierCreator(string ID, LoggerI* lg, string working_path)
{
	this->ID = ID;
	this->lg = lg;
	this->working_path = working_path;
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

void HaarClassifierCreator::good_normalization(string opencv_createsamples_util_path, string dst_path, string dst_name, double width, double height)
{	
	string cmd = opencv_createsamples_util_path + " -info " +
		working_path + "\\Good.dat -vec " + dst_path + "\\" +
		dst_name + "_samples.vec -w " + to_string(width) + " -h " + to_string(height);
	system(cmd.c_str());
}

void HaarClassifierCreator::training(string opencv_createsamples_util_path, string dst_path, string normal_srs, int cascade_levels, double quality_k, double false_k, int good_count, int bad_count, double width, double height, int allocated_memory)
{
	string cmd = opencv_createsamples_util_path + " -data " + dst_path + " -vec " + normal_srs +
		" -bg " + working_path + "\\Bad.dat -numStages " + to_string(cascade_levels) + " -minhitrate " + to_string(quality_k) +
		" -maxFalseAlarmRate " + to_string(false_k) + " -numPos " + to_string(good_count) + " -numNeg " + to_string(bad_count) +
		" -w " + to_string(width) + " -h " + to_string(height) + " -mode ALL -precalcValBufSize " +
		to_string(allocated_memory / 2) + " -precalcIdxBufSize " + to_string(allocated_memory / 2);
	system(cmd.c_str());
}

