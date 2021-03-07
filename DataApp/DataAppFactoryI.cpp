#include "DataAppFactoryI.h"

DataAppFactoryI::DataAppFactoryI(string ID, LoggerI* lg)
{
	this->ID = ID;
	this->lg = lg;
	if (lg != nullptr)
		lg->log(1, "abstract_factory:DataAppFactoryI:DataAppFactoryI:" + ID +
			":factory " + ID + " for data app created:");
}
