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