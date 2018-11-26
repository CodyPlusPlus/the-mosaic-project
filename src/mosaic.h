// File: mosaic.h
// Author: Cody Stuck
// Description: Contains the function declaration of makeMosaic()

#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <iostream>
#include <exception>

// makeMosaic: converts an image into a mosaic using a set of smaller images
// preconditions: the mosaic image and tile images should be square and grayscale, the dimensions of the mosaic image should be a multiple of the dimensions of the tile images
// postconditions: a new mat will be returned
cv::Mat makeMosaic(const cv::Mat &input, int n);