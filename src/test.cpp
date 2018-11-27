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

	REQUIRE(treeRoot.size() > 0);

	cv::Mat fromTree = treeRoot[0];

	bool isSame = test.rows == fromTree.rows && test.cols == fromTree.cols;

	REQUIRE(isSame);
}

int main(int argc, char ** argv) {
	int result = Catch::Session().run(argc, argv);
	system("PAUSE");
	return result;
}