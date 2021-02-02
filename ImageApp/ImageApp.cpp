#include "../internal/Logger/Logger.h"

#include <iostream>
#include "MatImage.h"

#include "../internal/Logger2/Logger2.h"
#include "../internal/Logger2/Logger2Director.h"
#include "../internal/Logger2/StandardLogger2Builder.h"

void LoggerTest() {
	// create chain
	Logger2Director* director = new Logger2Director("lg_dir", new StandardLogger2Builder("lg_s_b"));
	Logger2* lg = director->Construct();
	lg->log(1, "Chain:Main:main:main:chain created:");
	lg->log(2, "Main:main:main:main not class:");
	lg->log(3, "unhandled log");
}	

int main() {
	LoggerTest();
}

