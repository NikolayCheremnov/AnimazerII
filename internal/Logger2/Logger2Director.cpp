#include "Logger2Director.h"

Logger2Director::Logger2Director(string ID, Logger2BuilderI* builder)
{
	this->ID = ID;
	Logger2Builder = builder;
}

Logger2* Logger2Director::Construct()
{
	Logger2Builder->MakeLoggersChain();
	return Logger2Builder->getResult();
}
