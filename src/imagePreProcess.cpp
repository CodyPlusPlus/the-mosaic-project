/* imagePreProcess:
 *
 * Filename: imagePreProcess.cpp
 * Author: Aleksandr Golovin (golo314@uw.edu)
 * Date: 26 Nov. 2018
 *
 */

#include "imagePreProcess.h"

#include <iostream>

std::string to_zero_lead(const int value, const unsigned precision) {
  std::ostringstream oss;
  oss << std::setw(precision) << std::setfill('0') << value;
  return oss.str();
}

Mat standardizeImage(Mat image, int blocks) {
  int minSize = std::min(image.rows, image.cols);

  // If blocks don't factor into the size of image
  if (minSize % blocks != 0) {
    double intPart = 0.0;
    double remainder = std::modf(((double)minSize / blocks), &intPart);
    if (remainder >= 0.5) {
      do {
        minSize++;
      } while (minSize % blocks != 0);
    } else {
      do {
        minSize--;
      } while (minSize % blocks != 0);
    }
  }
  resize(image, image, Size(minSize, minSize));
  return image;
}

void loadImagesIntoTree(Tree & imageTree, int blocks) {
  for (int i = 1; i < 2828; i++) {
    std::string filename = "Emoji/" + to_zero_lead(i, 4) + ".png";
    Mat newImage = cv::imread(filename, cv::ImreadModes::IMREAD_GRAYSCALE);
    if (!newImage.empty()) {
      resize(newImage, newImage, Size(blocks, blocks));
      imageTree.addImage(newImage);
    }
  }
}
