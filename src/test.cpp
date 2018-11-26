#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "print.hpp"
#include "mosaic.h"



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

