#pragma once
#include "DataSetPacker.h"

#include <iostream>
#include "../internal/FileSystemManager/FileSystemManager.h"
#include "HaarContext.h"

#include <opencv2/core/types.hpp>

using namespace cv;

class HaarClassifierCreator :
	public DataSetPacker
{
private:
	

	string working_path;

	int write_bad_dat_file();
	int write_good_dat_file(Point p1, Point p2);
	void good_normalization(string opencv_createsamples_util_path,
		string dst_path, string dst_name, string width, string height, string good_size);
	void training(string traincascade_util_path, string dst_path,
		string normal_srs, string cascade_levels, string quality_k, string false_k,
		string good_count, string bad_count, string width, string height, string allocated_memory);

public:
	HaarClassifierCreator(string ID, LoggerI* lg);

	void DatasetPack(FrameProcessorContext* super_context, string config_file);
};