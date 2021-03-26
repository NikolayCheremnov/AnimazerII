#include "gtest/gtest.h"
#include "../internal/FileSystemManager/FileSystemManager.h"

#define BASE_TEST_DIR string("D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\testData\\unit_test_data\\")

#include <list>


TEST(TestFileSystemManager, Test_VerifyExistense) {
	EXPECT_TRUE(FileSystemManager::verify_existence(BASE_TEST_DIR));
	EXPECT_FALSE(FileSystemManager::verify_existence(BASE_TEST_DIR + "not_exist"));
	EXPECT_TRUE(FileSystemManager::verify_existence(BASE_TEST_DIR + "existing_file.txt"));
	EXPECT_FALSE(FileSystemManager::verify_existence(BASE_TEST_DIR + "not_existing_file.txt"));
}

TEST(TestFileSystemManager, Test_getAllDirFiles) {
	list<string> res = FileSystemManager::getAllDirFiles(BASE_TEST_DIR);
	if (res.size() != 5)
		FAIL();
}

TEST(TestFileSystemManager, Test_getAllDirFilesShort) {
	list<string> res = FileSystemManager::getAllDirFilesShort(BASE_TEST_DIR);
	if (res.size() != 5)
		FAIL();
}

TEST(TestFileSystemManager, Test_create_subdir) {
	FileSystemManager::create_subdir(BASE_TEST_DIR, "subdir");
	try {
		FileSystemManager::create_subdir(BASE_TEST_DIR + "not_exist\\", "subdir");
		FAIL();
	}
	catch (exception ex) {
		
	}
}

TEST(TestFileSystemManager, Test_read_file_to_map_params) {
	map<string, string> params = FileSystemManager::read_file_to_map_params(BASE_TEST_DIR + "map_params.txt");
	EXPECT_EQ(params["first_param"], "first");
	EXPECT_EQ(params["second_param"], "second");
	EXPECT_EQ(params["third_param"], "third");
}

TEST(TestFileSystemManager, Test_delete_dir_with_all_files) {
	FileSystemManager::create_subdir(BASE_TEST_DIR, "files");
	FileSystemManager::create_subdir(BASE_TEST_DIR + "files//", "f1");
	FileSystemManager::delete_dir_with_all_files(BASE_TEST_DIR + "files");
	FileSystemManager::delete_dir_with_all_files(BASE_TEST_DIR + "subdir");
}