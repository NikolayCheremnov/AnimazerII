#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Images //////////////////////

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

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	//imwrite("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\image_detected.jpg", img);
	imshow("Image", img);
	waitKey(0);
}


//