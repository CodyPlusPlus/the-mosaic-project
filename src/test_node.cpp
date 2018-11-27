#include "catch.hpp"
#include "Node.h"

TEST_CASE("Gets correct average pixel intensity") {
	cv::Mat test(0, 0, CV_8U); // Values should all default to 0

	Node tester(test);

	REQUIRE(tester.getAverage() == 0);
}