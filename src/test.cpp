#define CATCH_CONFIG_RUNNER  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "print.hpp"
#include "mosaic.h"
#include "Tree.hpp"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


TEST_CASE("Prints hello world") {
	REQUIRE(printHelloWorld() == "Hello World!");
}

TEST_CASE("Tests mosaic function")
{
	cv::Mat test = cv::imread("mosaictest.jpg", cv::ImreadModes::IMREAD_GRAYSCALE);
	cv::Mat test2 = makeMosaic(test, 100);
	cv::imwrite("out.jpg", test2);
	cv::imwrite("outorig.jpg", test);
}

TEST_CASE("Tests Tree Constructor") {
	cv::Mat test(5,5, CV_8U); // Values should all default to 0

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

int main(int argc, char ** argv) {
	int result = Catch::Session().run(argc, argv);
	system("PAUSE");
	return result;
}