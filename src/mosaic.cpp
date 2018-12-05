/* mosaic : Contains implementation of functions
 *
 * File: mosaic.cpp
 * Author: Cody Stuck
 *
 */

#include "mosaic.h"

// Implementation : allocateTiles
std::vector<cv::Mat> allocateTiles(const cv::Mat &inputImage, int n) {
  // Vector to return
  std::vector<cv::Mat> tiles;

  // For all the rows and columns of the image
  for (int tileR = 0; tileR < inputImage.rows; tileR += n) {
    for (int tileC = 0; tileC < inputImage.cols; tileC += n) {
      // Add tile corresponding tile to vector
      tiles.push_back(inputImage(cv::Rect(tileC, tileR, n, n)));
    }
  }

  // Return vector
  return (tiles);
}

// Implementation : fillTiles
void fillTiles(std::vector<cv::Mat> &tiles, const Tree &fillImages) {
  // For all the tiles in vector
  for (int i = 0; i < tiles.size(); i++) {
    // Get the average intensity
    int avgIntensity = cv::mean(tiles[i])[0];

    // Get a subimage from tree with close/matching intensity
    cv::Mat retrievedTile fillImages.getImage(avgIntensity);

    // For the rows and cols in tile
    for (int r = 0; r < tiles[i].rows; r++) {
      for (int c = 0; c < tiles[i].cols; c++) {
        // Overwrite pixel in tile image with that of retrieved image
        tiles[i].at<uchar>(r, c) = retrievedTile.at<uchar>(r, c);
      }
    }
  }
}

// Implementation : makeMosaic
cv::Mat makeMosaic(const cv::Mat &input, int n, const Tree &subimages) {
  // Create image to return
  cv::Mat mosaic = input.clone();

  // create vector of tiles
  std::vector<cv::Mat> tiles = allocateTiles(mosaic, n);

  // step through vector of tiles and fill with mean value
  fillTiles(tiles, subimages);

  // Return mosaic
  return (mosaic);
}
