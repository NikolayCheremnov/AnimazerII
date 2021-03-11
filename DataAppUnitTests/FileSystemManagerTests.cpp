#include "pch.h"
#include "CppUnitTest.h"

#include "FileSystemManager.cpp"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileSystemManagerTests
{
	// file system manager tests
	TEST_CLASS(FileSystemManagerTests)
	{
	public:

		TEST_METHOD(TestVerifyExistense)
		{
			Assert::IsTrue(FileSystemManager::verify_existence(BASE_TEST_DIR + "existing_file.txt"));
			Assert::IsFalse(FileSystemManager::verify_existence(BASE_TEST_DIR + "not_existing_file.txt"));
			Assert::IsTrue(FileSystemManager::verify_existence(BASE_TEST_DIR));
			Assert::IsFalse(FileSystemManager::verify_existence(BASE_TEST_DIR + "not_existing_path"));
		}
		TEST_METHOD(TestGetAllDirFiles)
		{
			list<string> fnames = FileSystemManager::getAllDirFiles(BASE_TEST_DIR + "files");
			Assert::AreEqual(int(fnames.size()), 2);
			Assert::AreEqual(fnames.front(), BASE_TEST_DIR + "files\\f1.txt");
			Assert::AreEqual(fnames.back(), BASE_TEST_DIR + "files\\f2.txt");
			fnames = FileSystemManager::getAllDirFilesShort(BASE_TEST_DIR + "files");
			Assert::AreEqual(int(fnames.size()), 2);
			Assert::AreEqual(fnames.front(), string("f1.txt"));
			Assert::AreEqual(fnames.back(), string("f2.txt"));
		}
		TEST_METHOD(TestCreateDeleteSubDir) 
		{
			FileSystemManager::create_subdir(BASE_TEST_DIR, "subdir");
			Assert::AreEqual(true, FileSystemManager::verify_existence(BASE_TEST_DIR + "subdir"));
			try {
				FileSystemManager::create_subdir(BASE_TEST_DIR, "subdir");
				Assert::Fail();
			}
			catch (exception ex) {
				Assert::AreEqual("couldn't create a directory", ex.what());
			}
			FileSystemManager::delete_dir_with_all_files(BASE_TEST_DIR + "subdir");
			Assert::AreEqual(false, FileSystemManager::verify_existence(BASE_TEST_DIR + "subdir"));
		}
		TEST_METHOD(TestDeleteDirWithAllFiles)
		{
			map <string, string> params = FileSystemManager::read_file_to_map_params(BASE_TEST_DIR + "\\map_params.txt");
			Assert::AreEqual(params["first_param"], string("first"));
			Assert::AreEqual(params["second_param"], string("second"));
			Assert::AreEqual(params["third_param"], string("third"));
		}
	};
}
