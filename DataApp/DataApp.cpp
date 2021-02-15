// DataApp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include "WebCamShooter.h"
#include "../internal/FileSystemManager/FileSystemManager.h"

using namespace cv;
using namespace std;

void captureTest() {
	WebCamShooter* wcs = new WebCamShooter("wcs", nullptr);
	wcs->set_object_rect(Point(200, 150), Point(500, 350));
	wcs->shoot_frames("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\dataset", 100);
	delete wcs;
}

void fsmTest() {
	cout << FileSystemManager::verify_existence("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP") << endl;
	cout << FileSystemManager::verify_existence("С:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP") << endl;
	cout << FileSystemManager::verify_existence("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\theme.txt") << endl;
	cout << FileSystemManager::verify_existence("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\theme.dat") << endl;
}

int main()
{
	captureTest();
	fsmTest();
}

