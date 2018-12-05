/* test_tree : A program to test tree class
 *
 * Filename : test_tree.cpp
 * Author : Brady Pascoe
 *
 */

#include "Tree.h"
#include "catch.hpp"

void setAllPixelsInImage(cv::Mat& img, const int setter) {
	for (int r = 0; r < img.rows; r++)
		for (int c = 0; c < img.cols; c++) img.at<char>(r, c) = setter;
}

TEST_CASE("Tests Tree Constructor") {
  cv::Mat test(5, 5, CV_8U);  // Values should all default to 0

  Tree testTree(test);

  std::vector<cv::Mat> treeRoot = testTree.getRoot()->data;

  REQUIRE(treeRoot.size() == 1);

  cv::Mat fromTree = treeRoot[0];

  REQUIRE((test.rows == fromTree.rows && test.cols == fromTree.cols));
}

TEST_CASE("Tree Add Function") {
  cv::Mat test(5, 5, CV_8U),
      test2(75, 74, CV_8U);  // Values should all default to 0

  Tree testTree(test);

  testTree.addImage(test2);

  std::vector<cv::Mat> treeRoot = testTree.getRoot()->data;

  REQUIRE(treeRoot.size() == 2);

  cv::Mat fromTree = treeRoot[0];

  REQUIRE((test.rows == fromTree.rows && test.cols == fromTree.cols));

  cv::Mat fromTree2 = treeRoot[1];

  REQUIRE((test2.rows == fromTree2.rows && test2.cols == fromTree2.cols));
}

TEST_CASE("Tree getImage returns a different Image on second iteration") {
	cv::Mat test1(5, 5, CV_8U);
	cv::Mat test2(10, 10, CV_8U);
	cv::Mat test3(15, 15, CV_8U);
	int commonPixel = 251;

	setAllPixelsInImage(test1, commonPixel);
	setAllPixelsInImage(test2, commonPixel);
	setAllPixelsInImage(test3, commonPixel);

	Tree tester(test1);

	tester.addImage(test2);
	tester.addImage(test3);

	cv::Mat returnImage = tester.getImage(commonPixel);

	REQUIRE((returnImage.rows == test1.rows && returnImage.cols == test1.cols));

	returnImage = tester.getImage(commonPixel);

	REQUIRE((returnImage.rows == test2.rows && returnImage.cols == test2.cols));
	
	returnImage = tester.getImage(commonPixel);

	REQUIRE((returnImage.rows == test3.rows && returnImage.cols == test3.cols));
}