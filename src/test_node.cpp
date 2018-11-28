#include "catch.hpp"
#include "Node.h"
#include<iostream>

void setAllPixels(cv::Mat& img, const int setter) {
	for (int r = 0; r < img.rows; r++)
		for (int c = 0; c < img.cols; c++)
			img.at<char>(r, c) = setter;
}

TEST_CASE("Gets correct average pixel intensity") {
	const int testIntensity = 0;

	cv::Mat test(3, 3, CV_8U); 
	
	setAllPixels(test, testIntensity);

	Node tester(test);

	REQUIRE(tester.getAverage() == testIntensity);
}

TEST_CASE("Orders the images correctly") {
	cv::Mat test1(3, 3, CV_8U);

	setAllPixels(test1, 0);

	cv::Mat test2(5, 5, CV_8U);

	setAllPixels(test2, 1);

	cv::Mat test3(7, 7, CV_8U);

	setAllPixels(test3, 2);

	Node tester(test2);

	tester.addImage(test1, 0);

	tester.addImage(test3, 2);

	bool isLeft = tester.left != 0 && (tester.left->data[0].rows == test1.rows && tester.left->data[0].cols == test1.cols);
	bool isRight = tester.right != 0 && (tester.right->data[0].rows == test3.rows && tester.right->data[0].cols == test3.cols);

	REQUIRE((isLeft && isRight));
}

TEST_CASE("getImages works on root") {
	cv::Mat test(75, 75, CV_8U);
	setAllPixels(test, 25);

	Node tester(test);

	std::vector<cv::Mat> getBack = tester.getImages(25);

	REQUIRE((getBack.size() == 1));
	REQUIRE((tester.left == 0 && tester.right == 0));
}

TEST_CASE("getImages works on leaf nodes") {
	cv::Mat test1(50, 50, CV_8U);
	cv::Mat test2(50, 50, CV_8U);
	cv::Mat test3(50, 50, CV_8U);

	setAllPixels(test1, 25);
	setAllPixels(test2, 50);
	setAllPixels(test3, 75);

	Node tester(test2);

	tester.addImage(test1, 25);
	tester.addImage(test3, 75);

	REQUIRE(tester.getImages(25).size() == 1);
	REQUIRE(tester.getImages(50).size() == 1);
	REQUIRE(tester.getImages(75).size() == 1);
}

TEST_CASE("getImages works for approximate intensities") {
	cv::Mat test1(50, 50, CV_8U);
	cv::Mat test2(50, 50, CV_8U);

	setAllPixels(test1, 28);
	setAllPixels(test2, 39);

	Node tester(test2);
	tester.addImage(test1, 28);

	std::vector<cv::Mat> getBack1 = tester.getImages(25);
	std::vector<cv::Mat> getBack2 = tester.getImages(31);

	REQUIRE((getBack1.size() == 1 && getBack2.size() == 1));
	REQUIRE((getBack1[0].rows == test1.rows && getBack1[0].cols == test1.cols));
	REQUIRE((getBack2[0].rows == test1.rows && getBack2[0].cols == test1.cols));
}