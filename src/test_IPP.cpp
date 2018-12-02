/* test_IPP : A test file for image pre-processing
 *
 * Filename: test_IPP.h
 * Author: Aleksandr Golovin (golo314@uw.edu)
 * Date: 26 Nov. 2018
 *
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

#include "Node.h"
#include "Tree.h"
#include "catch.hpp"
#include "imagePreProcess.h"

TEST_CASE("Test function that standardizes an image dimesion") {
  // Test even image dimesion with even subimage size
  REQUIRE((standardizeSize(10, 2) == 10));

  // Test even image dimesion with odd subimage size that factors
  REQUIRE((standardizeSize(10, 5) == 10));

  // Test even image dimesion with odd subimage size that does NOT factor
  REQUIRE((standardizeSize(10, 3) == 9));

  // Test odd image dimesion with odd subimage size
  REQUIRE((standardizeSize(9, 3) == 9));

  // Test odd image dimesion with odd subimage that does NOT factor
  REQUIRE((standardizeSize(13, 3) == 12));
}

TEST_CASE("Test function that standarizes entire image") {
  // Create a square image, with even dimesions
  cv::Mat test1(10, 10, CV_8U);

  // Test standardize with an even subimage that factors
  cv::Mat results = standardizeImage(test1, 2);
  REQUIRE((test1.rows == results.rows && test1.cols == results.cols));

  // Test standardize with an odd subimage that factors
  results = standardizeImage(test1, 5);
  REQUIRE((test1.rows == results.rows && test1.cols == results.cols));

  // Test standardize with an even subimage that does not factor
  cv::Mat test2(8, 8, CV_8U);
  results = standardizeImage(test1, 4);
  REQUIRE((test2.rows == results.rows && test2.cols == results.cols));

  // Test standardize with an odd subimage that does not factor
  cv::resize(test2, test2, cv::Size(9, 9));
  results = standardizeImage(test1, 3);
  REQUIRE((test2.rows == results.rows && test2.cols == results.cols));

  // Create a square image, with odd dimesions
  cv::resize(test1, test1, cv::Size(9, 9));

  // Test standardize with an odd subimage that factors
  results = standardizeImage(test1, 3);
  REQUIRE((test1.rows == results.rows && test1.cols == results.cols));

  // Test standardize with an odd subimage that does NOT factor
  cv::resize(test2, test2, cv::Size(5, 5));
  results = standardizeImage(test1, 5);
  REQUIRE((test2.rows == results.rows && test2.cols == results.cols));

  // Test standardize with an even subimage that does NOT factor
  cv::resize(test2, test2, cv::Size(8, 8));
  results = standardizeImage(test1, 2);
  REQUIRE((test2.rows == results.rows && test2.cols == results.cols));

  // Create an image with even rectangle
  cv::resize(test1, test1, cv::Size(6, 12));

  // Test standardize with an even subimage that factors
  results = standardizeImage(test1, 2);
  REQUIRE((test1.rows == results.rows && test1.cols == results.cols));

  // Test standardize with an odd subimage that factors
  results = standardizeImage(test1, 3);
  REQUIRE((test1.rows == results.rows && test1.cols == results.cols));

  // Test standardize with an even subimage that factors into only on dime.
  cv::resize(test2, test2, cv::Size(4, 12));
  results = standardizeImage(test1, 4);
  REQUIRE((test2.rows == results.rows && test2.cols == results.cols));
}

TEST_CASE("Test load tree") {
  // Create a tree
  Tree test;

  // Make sure root is null
  REQUIRE((test.getRoot() == nullptr));

  // Create an image
  cv::Mat test1(10, 10, CV_8U);

  // Load image to tree
  test.addImage(test1);

  // Make sure root is not null
  REQUIRE((test.getRoot() != nullptr));
}
