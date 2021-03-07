#include "HaarSubsystemFactory.h"

HaarSubsystemFactory::HaarSubsystemFactory(string ID, LoggerI* lg) : DataAppFactoryI(ID, lg)
{

}

OnOffMatFrameSourceI* HaarSubsystemFactory::create_on_off_frame_source(string ID, LoggerI* lg, map<string, string> args)
{
	try {
		return new MatFrameSourceAdapter(ID + "_mfsa_by_" + this->ID, lg, args["source_name"]);
	}
	catch (exception ex) {
		if (lg != nullptr)
			lg->log(2, "HaarSubsystemFactory:create_on_off_frame_source:" + this->ID + ":" + "bad args" + ":");
		throw ex;
	}
}

DataManagerI* HaarSubsystemFactory::create_data_manager(string ID, LoggerI* lg, map<string, string> args)
{
	try {
		return new HaarClassifierManager(ID + "_hcm_by_" + this->ID, lg, args["working_path"], create_on_off_frame_source(ID, lg, args));
	}
	catch (exception ex) {
		if (lg != nullptr)
			lg->log(2, "HaarSubsystemFactory:create_data_manager:" + this->ID + ":" + "bad args" + ":");
		throw ex;
	}
}

FrameProcessorContext* HaarSubsystemFactory::create_context(string ID, LoggerI* lg, map<string, string> args)
{
	return new HaarContext(ID + "_hc_by_" + this->ID, lg);
}

DataSetPacker* HaarSubsystemFactory::create_data_set_packer(string ID, LoggerI* lg, map<string, string> args)
{
	return new HaarClassifierCreator(ID + "_hcc_by_" + this->ID, lg);
}


