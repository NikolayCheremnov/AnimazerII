// DataApp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include "../internal/MatFrameSource/MatFrameSourceI.h"
#include "../internal/MatFrameSource/WebCamSource.h"
#include "../internal\FileSystemManager\FileSystemManager.h"
#include "HaarClassifierManager.h"
#include "DataManagerI.h"

using namespace cv;
using namespace std;

void DeleteAllFilesTesting() {
	FileSystemManager::delete_dir_with_all_files("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\haar\\Good\\");
	FileSystemManager::delete_dir_with_all_files("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\haar\\Bad\\");
}

void DataManagerTest() {
	DataManagerI* dm = new HaarClassifierManager("hcm_test", nullptr, "D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\haar",
		new WebCamSource("hcm_wcs_test", nullptr, 0));
	dm->DatasetCreating(4000, 3000);
}

void DataSetCreatingTest() {
	HaarClassifierManager* hcm = new HaarClassifierManager("hcm", nullptr, 
		"D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\haar", 
		new WebCamSource("wcs_test", nullptr, 0));
	hcm->DatasetCreating(10, 10);
	delete hcm;
}

void WebCamSourceTest() {
	MatFrameSourceI* mfs = new WebCamSource("wcs_test", nullptr, 0);
	Mat frame = mfs->get_frame();
	imshow("wcs_test", frame);
	waitKey(0);
	delete mfs;
}

void ReadFileToMapParamsTest() {
	map<string, string> params = FileSystemManager::read_file_to_map_params("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\haar\\haar_creator_config.txt");
	for (map<string, string>::iterator it = params.begin(); it != params.end(); it++)
		cout << it->first << ':' << it->second << endl;
}

int main()
{
	//captureTest();
	setlocale(LC_ALL, "");
	//WebCamSourceTest();
	//DataSetCreatingTest();
	//ReadFileToMapParamsTest();
	DeleteAllFilesTesting();
}

/*/
void captureTest() {
	WebCamShooter* wcs = new WebCamShooter("wcs", nullptr);
	wcs->set_object_rect(Point(200, 150), Point(500, 350));
	wcs->_shoot_frames("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\haar", 100, "");
	delete wcs;
}

void fsmTest() {
	cout << FileSystemManager::verify_existence("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP") << endl;
	cout << FileSystemManager::verify_existence("С:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP") << endl;
	cout << FileSystemManager::verify_existence("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\theme.txt") << endl;
	cout << FileSystemManager::verify_existence("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\theme.dat") << endl;
}

void DataSetCreatingTest(string wd) {
	HaarClassifierManager* hcm = new HaarClassifierManager("hcm", nullptr, wd);
	hcm->DatasetCreating();
	delete hcm;
}
/*/