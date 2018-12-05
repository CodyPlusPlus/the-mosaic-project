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
#include "Tree.h"

// allocateTiles: creates a vector of mats that refer to a larger mat
// precondtions: the dimensions of the mat should be divisible by n
// postconditions: a vector of nxn tile mats is returned
std::vector<cv::Mat> allocateTiles(const cv::Mat &inputImage, int n);

// fillTiles: replaces the contents of a vector of Mats with images of nearest values retrieved from a tree
// postconditions: the Mats in the vector will be overwritten
void fillTiles(std::vector<cv::Mat> &tiles, const Tree &fillImages);

// makeMosaic: converts an image into a mosaic using a set of smaller images
// preconditions: the mosaic image and tile images should be square and grayscale, the dimensions of the mosaic image should be a multiple of the dimensions of the tile images
// postconditions: a new mat will be returned
cv::Mat makeMosaic(const cv::Mat &input, int n, const Tree &subimages);