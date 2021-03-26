#include "gtest/gtest.h"

#include "../Detector/CascadeProcessor.h"
#include "../ImageApp/Image.h"
#include "../ImageApp/SingleImage.h"
#include "../ImageApp/DetectableImage.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

TEST(TestCascadeProcessor, Test_CreateCascadeProcessor) {
	CascadeProcessor* prc = new CascadeProcessor("cp", nullptr);
	delete prc;
}

TEST(TestCascadeProcessor, Test_prepare) {
	CascadeProcessor* prc = new CascadeProcessor("cp", nullptr);
	prc->set_path("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\cascades\\haarcascade_frontcatface.xml");
	prc->prepare();
	delete prc;
}

TEST(TestCascadeProcessor, Test_process) {
	Image* img = new SingleImage("single_img", nullptr);
	img->SetImageObj(new MatImage("mat_img", nullptr));
	img->set_path(BASE_TEST_DIR + "good.jpg");
	DetectableImage* d_img = new DetectableImage("detectable_img", nullptr, img, "undefined");
	d_img->PerformImageLoad();
	EXPECT_EQ(d_img->GetInfoStr(), "UNDEFINED");
	CascadeProcessor* prc = new CascadeProcessor("cp", nullptr);
	prc->set_path("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\cascades\\haarcascade_frontcatface.xml");
	prc->process(d_img);
	EXPECT_EQ(d_img->GetInfoStr(), "UNDEFINED");
	prc->prepare();
	prc->process(d_img);
	EXPECT_EQ(d_img->GetInfoStr(), "POSITIVE");
	d_img->set_path(BASE_TEST_DIR + "bad.jpg");
	d_img->PerformImageLoad();
	prc->process(d_img);
	EXPECT_EQ(d_img->GetInfoStr(), "NEGATIVE");
	delete d_img;
	delete prc;
}
