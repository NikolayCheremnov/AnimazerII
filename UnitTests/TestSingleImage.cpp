#include "gtest/gtest.h"
#include "../ImageApp/SingleImage.h"
#include "../ImageApp/ImageObj.h"
#include "../ImageApp/MatImage.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

TEST(TestSingleImage, Test_CreateSingleImage) {
	SingleImage* si = new SingleImage("si_test", nullptr);
	delete si;
}

TEST(TestSingleImage, Test_PerformImageLoad) {
	SingleImage* si = new SingleImage("si_test", nullptr);
	si->PerformImageLoad();
	ImageObj* io = si->getImageObj();
	EXPECT_EQ(io, nullptr);
	si->SetImageObj(new MatImage("mat_img", nullptr));
	si->PerformImageLoad();
	try {
		si->getImageObj()->show("test");
		FAIL();
	}
	catch (exception ex) {

	}
	si->set_path(BASE_TEST_DIR + "bad.jpg");
	si->PerformImageLoad();
	io = si->getImageObj();
	delete si;
}

TEST(TestSingleImage, Test_clone) {
	SingleImage* si = new SingleImage("si_test", nullptr);
	si->SetImageObj(new MatImage("mat_img", nullptr));
	si->set_path(BASE_TEST_DIR + "bad.jpg");
	si->PerformImageLoad();
	Image* si_2 = si->clone();
	delete si;
	si_2->getImageObj();
	delete si_2;
}