#include "gtest/gtest.h"

#include "../internal/Logger2/Logger2.h"
#include "../internal/Logger2/Logger2Director.h"
#include "../internal/Logger2/StandardLogger2Builder.h"
#include "../internal/api/LoggerI.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

TEST(TestLogger, Test_LoggerConstruct) {
	Logger2Director* director = new Logger2Director("lg_dir", new StandardLogger2Builder("lg_s_b"));
	Logger2* lg = director->Construct();
	delete director;
	delete lg;
}

TEST(TestLogger, Test_log) {
	Logger2Director* director = new Logger2Director("lg_dir", new StandardLogger2Builder("lg_s_b"));
	LoggerI* lg = director->Construct();
	lg->log(1, "test:test:test:test:test:");
	lg->log(2, "test:test:test:test:");
	lg->log(3, "test");
}