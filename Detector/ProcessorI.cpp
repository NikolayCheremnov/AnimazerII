#include "ProcessorI.h"

ProcessorI::ProcessorI(string ID, LoggerI* lg)
{
	this->ID = ID;
	this->lg = lg;
	if (lg != nullptr)
		lg->log(3, "'ProcessorI' object " + ID + " was create");
}
