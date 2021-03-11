#include "pch.h"
#include "CppUnitTest.h"

#include "HaarSubsystemFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HaarSubSystemFactoryTests
{
	// HaarSubsystemFactory class testing
	TEST_CLASS(HaarSubSystemFactoryTests)
	{
	public:

		TEST_METHOD(CreateHaarSubsystemFactoryTest)
		{
			HaarSubsystemFactory* hsf = new HaarSubsystemFactory("hsf_test", nullptr);
			delete hsf;
		}
		TEST_METHOD(CreateOnOffFrameSource)
		{
			map <string, string> params;
			params["source_name"] = "WebCamSource";
			HaarSubsystemFactory* hsf = new HaarSubsystemFactory("hsf_test", nullptr);
			OnOffMatFrameSourceI* oomfs = hsf->create_on_off_frame_source("oomfs_test", nullptr, params);
			delete oomfs;
			params["source_name"] = "BadSource";
			try {
				OnOffMatFrameSourceI* oomfs = hsf->create_on_off_frame_source("oomfs_test", nullptr, params);
				oomfs->turn_on();
				oomfs->get_frame();
				Assert::Fail();
			}
			catch (exception ex) {

			}
			params.clear();
			params["foo"] = "bar";
			try {
				OnOffMatFrameSourceI* oomfs = hsf->create_on_off_frame_source("oomfs_test", nullptr, params);
				oomfs->turn_on();
				oomfs->get_frame();
				Assert::Fail();
			}
			catch (exception ex) {

			}
			delete hsf;
		}
		TEST_METHOD(CreateDataManagerTest)
		{
			HaarSubsystemFactory* hsf = new HaarSubsystemFactory("hsf_test", nullptr);
			map <string, string> params;
			params["source_name"] = "WebCamSource";
			params["working_path"] = "D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\working_path";
			DataManagerI* dm = hsf->create_data_manager("dm_test", nullptr, params);
			delete dm;
			params.clear();
			try {
				DataManagerI* dm = hsf->create_data_manager("dm_test", nullptr, params);
				Assert::Fail();
			}
			catch (exception ex) {

			}
			delete hsf;
		}
		TEST_METHOD(CreateContextTest)
		{
			HaarSubsystemFactory* hsf = new HaarSubsystemFactory("hsf_test", nullptr);
			map <string, string> params;
			FrameProcessorContext* fpc = hsf->create_context("fpc", nullptr, params);
			delete fpc;
			delete hsf;
		}
		TEST_METHOD(CreateDatasetPacker)
		{
			HaarSubsystemFactory* hsf = new HaarSubsystemFactory("hsf_test", nullptr);
			map <string, string> params;
			DataSetPacker* dsp = hsf->create_data_set_packer("dsp", nullptr, params);
			delete dsp;
			delete hsf;
		}
	};
}
