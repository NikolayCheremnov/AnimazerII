#include "pch.h"
#include "CppUnitTest.h"
#include "../DataApp/HaarContext.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HaarContextTests
{
	// test example
	TEST_CLASS(HaarContextTests)
	{
	public:

		TEST_METHOD(TestSaveContext)
		{
			HaarContext* hc = new HaarContext("hc_test", nullptr);
			hc->set_context("test", "test", "test", 100);
			hc->set_context_with_rect("test", Point(0, 0), Point(1, 1), "test", 100);
			for (int i = 0; i < 10; i++) {
				hc->good_inc();
				hc->bad_inc();
			}
			try {
				hc->SaveContext(BASE_TEST_DIR);
				Assert::Fail();
			}
			catch (exception ex) {

			}
			hc->SaveContext(BASE_TEST_DIR + "test_context.txt");
			delete hc;
		}
		TEST_METHOD(TestLoadContext)
		{
			HaarContext* hc = new HaarContext("hc_test", nullptr);
			hc->LoadContext(BASE_TEST_DIR + "test_context.txt");
			Assert::AreEqual(hc->get_bad(), 10);
			Assert::AreEqual(hc->get_good(), 10);
			Assert::AreEqual(hc->get_header(), string("test"));
			Assert::AreEqual(hc->get_mode(), 100);
			Assert::AreEqual(hc->get_path(), string("test"));
			Assert::AreEqual(hc->get_rect("p1")->x, 0);
			Assert::AreEqual(hc->get_rect("p1")->y, 0);
			Assert::AreEqual(hc->get_rect("p2")->x, 1);
			Assert::AreEqual(hc->get_rect("p2")->y, 1);
			Assert::AreEqual(hc->get_rect_str(), string("test"));
			delete hc;
		}

	};
}
