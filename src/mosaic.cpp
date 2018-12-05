// File: mosaic.cpp
// Author: Cody Stuck
// Description: Contains the function definition of makeMosaic()

#include "mosaic.h"

// allocateTiles: creates a vector of mats that refer to a larger mat
// precondtions: the dimensions of the mat should be divisible by n
// postconditions: a vector of nxn tile mats is returned
std::vector<cv::Mat> allocateTiles(const cv::Mat &inputImage, int n) {
  std::vector<cv::Mat> tiles;

  for (int tileR = 0; tileR < inputImage.rows; tileR += n) {
    for (int tileC = 0; tileC < inputImage.cols; tileC += n) {
      tiles.push_back(inputImage(cv::Rect(tileC, tileR, n, n)));
    }
  }

  return (tiles);
}

// fillTiles: replaces the contents of a vector of Mats with images of nearest
// values retrieved from a tree postconditions: the Mats in the vector will be
// overwritten
void fillTiles(std::vector<cv::Mat> &tiles, const Tree &fillImages) {
  for (int i = 0; i < tiles.size(); i++) {
    int avgIntensity = cv::mean(tiles[i])[0];
    cv::Mat retrievedTile;

    for (int r = 0; r < tiles[i].rows; r++) {
      for (int c = 0; c < tiles[i].cols; c++) {
        retrievedTile = fillImages.getImage(avgIntensity);
        tiles[i].at<uchar>(r, c) = retrievedTile.at<uchar>(r, c);
      }
    }
  }
}

// makeMosaic: converts an image into a mosaic using a set of smaller images
// preconditions: the mosaic image and tile images should be square and
// grayscale, the dimensions of the mosaic image should be a multiple of the
// dimensions of the tile images postconditions: a new mat will be returned
cv::Mat makeMosaic(const cv::Mat &input, int n, const Tree &subimages) {
  cv::Mat mosaic = input.clone();

  // create vector of tiles
  std::vector<cv::Mat> tiles = allocateTiles(mosaic, n);

  // step through vector of tiles and fill with mean value
  fillTiles(tiles, subimages);

  return (mosaic);
}
