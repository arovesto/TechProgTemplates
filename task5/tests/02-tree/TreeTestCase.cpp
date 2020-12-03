//
// Created by akhtyamovpavel on 5/1/20.
//

#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <gtest/gtest.h>

#include "TreeTestCase.h"
#include "Tree.h"

using namespace boost::filesystem

TEST(B, TreeFail) {
	ASSERT_THROW(GetTree("path-not-exists", false), std::invalid_argument);
	ASSERT_THROW(GetTree("path-not-exists", true), std::invalid_argument);
	ofstream file("real-file");
	ASSERT_THROW(GetTree("real-file", true), std::invalid_argument);
};

TEST(B, TreeDirs) {
	string tmpDir = boost::filesystem::temp_directory_path().string();

	FileNode node1;
	node1.name = "folder";
	node1.is_dir = true;

	FileNode node2;
	node2.name = "subfolder";
	node2.is_dir = true;
	node1.children.push_back(node2);

	ASSERT_EQ(GetTree(tmpDir + "/folder", true), node1);
}

TEST(B, TreeDirsWithFiles) {
	string tmpDir = boost::filesystem::temp_directory_path().string();

	FileNode node1;
	node1.name = "folder";
	node1.is_dir = true;
	
	FileNode node2;
	node2.name = "subfolder";
	node2.is_dir = true;
	node1.children.push_back(node2);
	
        FileNode node3;
	node3.name = "file";
	node3.is_dir = false;
	node1.children.push_back(node3);

	ASSERT_EQ(GetTree(tmpDir + "/folder", false), node1);
}

