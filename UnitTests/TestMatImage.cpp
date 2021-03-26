#include "gtest/gtest.h"
#include "../ImageApp/MatImage.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

TEST(TestMatImage, Test_MatImageCreate) {
	MatImage* mi = new MatImage("mi_test", nullptr);
	delete mi;
}

TEST(TestMatImage, Test_init) {
	MatImage* mi = new MatImage("mi_test", nullptr);
	mi->init("foo");
	EXPECT_EQ(mi->getMatImg()->cols, 0);
	mi->init(BASE_TEST_DIR + "bad.jpg");
	ASSERT_NE(mi->getMatImg()->cols, 0);
	delete mi;
}