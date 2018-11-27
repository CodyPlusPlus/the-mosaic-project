#include "catch.hpp"
#include "Utility.h"
#include <opencv2/core/core.hpp>

TEST_CASE("Gets average pixel intensity of the image") {
	cv::Mat test(5, 5, CV_8U); // Values should all default to 0

	int commonIntensity = getAvergePixelIntensity(test);

	REQUIRE(commonIntensity == 0);
}

