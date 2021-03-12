#include "pch.h"
#include "CppUnitTest.h"
#include "../internal/MatFrameSource/WebCamSource.h"
#include "../internal/MatFrameSource/MatFrameSourceAdapter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FrameSourceTests
{
	// test example
	TEST_CLASS(FrameSourceTests)
	{
	public:
		
		// web cam source tests
		TEST_METHOD(TestWebCamSourceCreate)
		{
			WebCamSource* wcs = new WebCamSource("wcs_test", nullptr, 0);
			delete wcs;
			try {
				wcs = new WebCamSource("wcs_test", nullptr, -1);
				Assert::Fail();
			}
			catch (exception ex) {
			
			}
		}
		TEST_METHOD(TestWebCamSourceGetFrame)
		{
			WebCamSource* wcs = new WebCamSource("wcs_test", nullptr, 0);
			Mat frame = wcs->get_frame();
			delete wcs;
		}
		TEST_METHOD(TestOnOffFrameSourceAdapter) // on off adapter tests
		{
			MatFrameSourceAdapter* mfsa = new MatFrameSourceAdapter("mfsa_test", nullptr, "WebCamSource");
			try {
				mfsa->get_frame();
				Assert::Fail();
			}
			catch (exception ex) {

			}
			mfsa->turn_on();
			mfsa->get_frame();
			mfsa->turn_off();
			try {
				mfsa->get_frame();
				Assert::Fail();
			}
			catch (exception ex) {

			}
			delete mfsa;
			mfsa = new MatFrameSourceAdapter("mfsa_test", nullptr, "BadSource");
			mfsa->turn_on();
			try {
				mfsa->get_frame();
				Assert::Fail();
			}
			catch (exception ex) {

			}
		}
	};
}
