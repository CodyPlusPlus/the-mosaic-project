/* test_main : main driver for all test programs
 *
 * Filename : test_main.cpp
 * Author(s) : Brady Pascoe, Cody Stuck
 *
 */

#define CATCH_CONFIG_RUNNER  // This tells Catch to provide a main() - only do
                             // this in one cpp file
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "catch.hpp"
#include "mosaic.h"

TEST_CASE("Test allocate tiles") {
  int n = 5, w = 50, h = 120;
  cv::Mat testMat(w, h, CV_8UC1);
  std::vector<cv::Mat> testTiles = allocateTiles(testMat, 5);
  REQUIRE(testTiles.size() == (w / n) * (h / n));
}

int main(int argc, char** argv) {
  int result = Catch::Session().run(argc, argv);
  system("PAUSE");
  return result;
}
