/* imagePreProcess.cpp : Contains actual implementation of the functions
 *
 * Filename: imagePreProcess.cpp
 * Author: Aleksandr Golovin (golo314@uw.edu)
 * Date: 26 Nov. 2018
 *
 */

#include "imagePreProcess.h"

// Implementation of padWithZeros
std::string padWithZeros(const int value, const unsigned precision) {
  // Create an ostringstream object
  std::ostringstream oss;

  // Write value to ostringstream object
  oss << std::setw(precision) << std::setfill('0') << value;

  // Return ostringstream object as string
  return oss.str();
}

// Implementation of standardizeSize
int standardizeSize(int imageDim, int blockSize) {
  // While subimage size does not factor into image dimesion
  while (imageDim % blockSize != 0) {
    // Decrement image dimesion
    imageDim--;
  }

  // Return correct image dimension
  return imageDim;
}

// Implementation of standardizeImage
Mat standardizeImage(Mat image, int block) {
  // Make sure that subimage factors into image evenly
  int newRows = standardizeSize(image.rows, block),
      newCols = standardizeSize(image.cols, block);

  // Resize the image
  resize(image, image, Size(newCols, newRows));

  // Return the image
  return image;
}

// Implementation of loadImagesIntoTree
void loadImagesIntoTree(Tree* imageTree, int block) {
  // For all the images from 1 to 2827
  for (int i = 1; i < 2828; i++) {
    // Generate relative path to image
    std::string filename = "Emoji/" + padWithZeros(i, 4) + ".png";

    // Load image and convert it to grayscale
    Mat newImage = imread(filename, ImreadModes::IMREAD_GRAYSCALE);

    // If image read-in successfully
    if (!newImage.empty()) {
      // Resize the image to correct size
      resize(newImage, newImage, Size(block, block));

      // Add image to tree
      imageTree->addImage(newImage);
    }
  }
}
