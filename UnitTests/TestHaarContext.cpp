#include "gtest/gtest.h"

#include "../DataApp/HaarContext.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

TEST(TestHaarContext, Test_HaarConextCreate) {
	HaarContext* hc = new HaarContext("hc_test", nullptr);
	delete hc;
}

TEST(TestHaarContext, Test_SaveConext) {
	HaarContext* hc = new HaarContext("hc_test", nullptr);
	hc->set_context("test", "test", "test", 100);
	hc->set_context_with_rect("test", Point(0, 0), Point(1, 1), "test", 100);
	for (int i = 0; i < 10; i++) {
		hc->good_inc();
		hc->bad_inc();
	}
	try {
		hc->SaveContext(BASE_TEST_DIR);
		FAIL();
	}
	catch (exception ex) {

	}
	hc->SaveContext(BASE_TEST_DIR + "test_context.txt");
	delete hc;
}

TEST(TestHaarContext, Test_LoadContext) {
	HaarContext* hc = new HaarContext("hc_test", nullptr);
	hc->LoadContext(BASE_TEST_DIR + "test_context.txt");
	EXPECT_EQ(hc->get_bad(), 10);
	EXPECT_EQ(hc->get_good(), 10);
	EXPECT_EQ(hc->get_header(), string("test"));
	EXPECT_EQ(hc->get_mode(), 100);
	EXPECT_EQ(hc->get_path(), string("test"));
	EXPECT_EQ(hc->get_rect("p1")->x, 0);
	EXPECT_EQ(hc->get_rect("p1")->y, 0);
	EXPECT_EQ(hc->get_rect("p2")->x, 1);
	EXPECT_EQ(hc->get_rect("p2")->y, 1);
	EXPECT_EQ(hc->get_rect_str(), string("test"));
	delete hc;
}