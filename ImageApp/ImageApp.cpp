#include "../internal/Logger/Logger.h"

#include <iostream>

#include "../internal/Logger2/Logger2.h"
#include "../internal/Logger2/Logger2Director.h"
#include "../internal/Logger2/StandardLogger2Builder.h"
#include "../internal/api/LoggerI.h"

#include "Image.h"
#include "SingleImage.h"
#include "MatImage.h"

LoggerI* LoggerTest() {
	// create chain
	Logger2Director* director = new Logger2Director("lg_dir", new StandardLogger2Builder("lg_s_b"));
	Logger2* lg = director->Construct();
	return lg;
}	

//
void SingleImageTest(LoggerI *lg) {
	Image* img = new SingleImage("single_img", lg);
	img->SetImageObj(new MatImage("mat_img", lg));
	img->set_path("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\image.jpg");
	img->PerformImageLoad();
}
//

int main() {
	LoggerI* lg = LoggerTest();
	SingleImageTest(lg);
}

