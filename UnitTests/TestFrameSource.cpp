#include "gtest/gtest.h"
#include "../internal/MatFrameSource/WebCamSource.h"
#include "../internal/MatFrameSource/MatFrameSourceAdapter.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")


TEST(TestWebCamSource, Test_WebCamSourceCreate) {
	WebCamSource* wcs = new WebCamSource("wcs_test", nullptr, 0);
	delete wcs;
	try {
		wcs = new WebCamSource("wcs_test", nullptr, -1);
		FAIL();
	}
	catch (exception ex) {

	}
}

TEST(TestWebCamSource, Test_get_frame) {
	WebCamSource* wcs = new WebCamSource("wcs_test", nullptr, 0);
	Mat frame = wcs->get_frame();
	delete wcs;
}

TEST(TestOnOffFrameSourceAdapter, Test_TestOnOffFrameSourceAdapterCreate) {
	MatFrameSourceAdapter* mfsa = new MatFrameSourceAdapter("mfsa_test", nullptr, "WebCamSource");
	delete mfsa;
}

TEST(TestOnOffFrameSourceAdapter, Test_turn_on_turn_off) {
	MatFrameSourceAdapter* mfsa = new MatFrameSourceAdapter("mfsa_test", nullptr, "WebCamSource");
	mfsa->turn_on();
	mfsa->turn_off();
	delete mfsa;
}

TEST(TestOnOffFrameSourceAdapter, Test_get_frame) {
	MatFrameSourceAdapter* mfsa = new MatFrameSourceAdapter("mfsa_test", nullptr, "WebCamSource");
	try {
		mfsa->get_frame();
		FAIL();
	}
	catch (exception ex) {

	}
	mfsa->turn_on();
	mfsa->get_frame();
	mfsa->turn_off();
	try {
		mfsa->get_frame();
		FAIL();
	}
	catch (exception ex) {

	}
	delete mfsa;
	mfsa = new MatFrameSourceAdapter("mfsa_test", nullptr, "BadSource");
	mfsa->turn_on();
	try {
		mfsa->get_frame();
		FAIL();
	}
	catch (exception ex) {

	}
}
