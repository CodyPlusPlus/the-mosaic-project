#include "catch.hpp"
#include "Tree.hpp"


TEST_CASE("Tests Tree Constructor") {
	cv::Mat test(5, 5, CV_8U); // Values should all default to 0

	Tree testTree(test);

	std::vector<cv::Mat> treeRoot = testTree.getRoot()->data;

	REQUIRE(treeRoot.size() == 1);

	cv::Mat fromTree = treeRoot[0];

	REQUIRE((test.rows == fromTree.rows && test.cols == fromTree.cols));
}

TEST_CASE("Tree Add Function") {
	cv::Mat test(5, 5, CV_8U), test2(75, 74, CV_8U); // Values should all default to 0

	Tree testTree(test);

	testTree.addImage(test2);

	std::vector<cv::Mat> treeRoot = testTree.getRoot()->data;

	REQUIRE(treeRoot.size() == 2);

	cv::Mat fromTree = treeRoot[0];

	REQUIRE((test.rows == fromTree.rows && test.cols == fromTree.cols));

	cv::Mat fromTree2 = treeRoot[1];

	REQUIRE((test2.rows == fromTree2.rows && test2.cols == fromTree2.cols));
}
