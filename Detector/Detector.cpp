#include <iostream>

// Logger
#include "../internal/Logger2/Logger2.h"
#include "../internal/Logger2/Logger2Director.h"
#include "../internal/Logger2/StandardLogger2Builder.h"
#include "../internal/api/LoggerI.h"

// Image
#include "../ImageApp/Image.h"
#include "../ImageApp/SingleImage.h"
#include "../ImageApp/MatImage.h"
#include "../ImageApp/DetectableImage.h"

// Processor
#include "CascadeProcessor.h"


using namespace std;

LoggerI* LoggerTest() {
	// create chain
	Logger2Director* director = new Logger2Director("lg_dir", new StandardLogger2Builder("lg_s_b"));
	Logger2* lg = director->Construct();
	return lg;
}
//
DetectableImage* StatusImageTest(LoggerI* lg) {
	Image* img = new SingleImage("single_img", lg);
	img->SetImageObj(new MatImage("mat_img", lg));
	img->set_path("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\43.bmp");
	DetectableImage* d_img = new DetectableImage("detectable_img", lg, img, "undefined");
	d_img->PerformImageLoad();
	d_img->SetInfo("false");
	return d_img;
}
//

void CascadeProcessorTesting(LoggerI* lg, Image* img) {
	CascadeProcessor* prc = new CascadeProcessor("cp", lg);
	prc->set_path("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\cascades\\haarcascade_frontcatface.xml");
	prc->prepare();
	prc->process(img);
	img->Show();
}

int main() {
	LoggerI* lg = LoggerTest();
	Image* img = StatusImageTest(lg);
	CascadeProcessorTesting(lg, img);
}

/*////////////// Images //////////////////////

void main() {

	string path = "D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\image.jpg";
	Mat img_s = imread(path);
	Mat img;
	resize(img_s, img, Size(), 2, 2);

	CascadeClassifier faceCascade;
	faceCascade.load("D:\\cpplibs\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> faces;
	system("pause");
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	//for (int i = 0; i < faces.size(); i++)
	//{
	//	rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	//}

	//imwrite("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\image_detected.jpg", img);
	imshow("Image", img);
	waitKey(0);
}


/*/