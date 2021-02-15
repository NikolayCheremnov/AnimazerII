#pragma once

#include <string>
#include <fstream>

#include "../internal/api/LoggerI.h"
#include "../internal/FileSystemManager/FileSystemManager.h"
#include <opencv2/core/types.hpp>

using namespace std;
using namespace cv;

class HaarClassifierCreator
{
private:
	string ID;
	LoggerI* lg;

	string working_path;

public:
	HaarClassifierCreator(string ID, LoggerI* lg, string working_path);

	void write_bad_dat_file();
	void write_good_dat_file(Point p1, Point p2);
	void good_normalization(string opencv_createsamples_util_path, 
		string dst_path, string dst_name, double width, double height);
	void training(string opencv_createsamples_util_path, string dst_path,
		string normal_srs, int cascade_levels, double quality_k, double false_k,
		int good_count, int bad_count, double width, double height, int allocated_memory);
};