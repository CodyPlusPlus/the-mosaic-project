/* mosic : Contains the declaration of makeMosaic()
 *
 * File: mosaic.h
 * Author: Cody Stuck
 *
 */

#pragma once

#include <exception>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include "Tree.h"

/* allocateTiles: creates a vector of mats that refer to a larger mat
 *
 * precondtions: the dimensions of the mat should be divisible by n
 * postconditions: a vector of nxn tile mats is returned
 * params :
 *     inputImage : image to get tiles from
 *     n : size of tiles
 *
 * returns : vector of files
 */
std::vector<cv::Mat> allocateTiles(const cv::Mat &inputImage, int n);

/* fillTiles: replaces the contents of a vector of Mats with images of nearest
 * 		values retrieved from a tree
 *
 * precondition : Tiles contains images, tree contains subimages
 * postconditions: the Mats in the vector will be overwritten
 * params:
 *     tiles : vector to be filled
 *     fillImages : tree from which subimages shall be pulled
 *
 */
void fillTiles(std::vector<cv::Mat> &tiles, const Tree &fillImages);

/* makeMosaic: converts an image into a mosaic using a set of smaller images
 *
 * preconditions: the mosaic image and tile images should be square and
 * 		grayscale, the dimensions of the mosaic image should be a multiple
 * 		of the dimensions of the tile images
 * postconditions: a new mat will be returned
 * params :
 *     input : Image to convert to mosaic
 *     n : Size of subimages
 *     subimages : tree with subimages
 *
 * returns : mosaic image
 */
cv::Mat makeMosaic(const cv::Mat &input, int n, const Tree &subimages);
