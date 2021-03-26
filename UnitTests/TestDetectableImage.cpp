#include "gtest/gtest.h"

#include "../ImageApp/DetectableImage.h"
#include "../ImageApp/SingleImage.h"
#include "../ImageApp/MatImage.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

TEST(TestDetectableImage, Test_DetectableImageCreate) {
	Image* img = new SingleImage("single_img", nullptr);
	DetectableImage* d_img = new DetectableImage("detectable_img", nullptr, img, "undefined");
	delete d_img;
}

TEST(TestDetectableImage, Test_PerformImageLoad) {
	Image* img = new SingleImage("single_img", nullptr);
	DetectableImage* d_img = new DetectableImage("detectable_img", nullptr, img, "undefined");
	d_img->SetImageObj(new MatImage("mat_img", nullptr));
	d_img->set_path(BASE_TEST_DIR + "good.jpg");
	d_img->PerformImageLoad();
	d_img->SetInfo("false");
	delete d_img;
}

TEST(TestDetectableImage, Test_clone) {
	Image* img = new SingleImage("single_img", nullptr);
	DetectableImage* d_img = new DetectableImage("detectable_img", nullptr, img, "undefined");
	d_img->SetImageObj(new MatImage("mat_img", nullptr));
	d_img->set_path(BASE_TEST_DIR + "good.jpg");
	d_img->PerformImageLoad();
	StatusImageI* d_img_2 = (StatusImageI * )d_img->clone();
	delete d_img;
	EXPECT_EQ(d_img_2->GetInfoStr(), "UNDEFINED");
	d_img_2->getImageObj();
	delete d_img_2;
}