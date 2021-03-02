#include "DataManagerI.h"

DataManagerI::DataManagerI(string ID, LoggerI* lg)
{
	this->lg = lg;
	this->ID = ID;
}
