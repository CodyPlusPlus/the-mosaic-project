#include <stdlib.h>
#include <iostream>
#include "Tree.h"
#include "imagePreProcess.h"
#include "mosaic.h"

int main(int argc, char* argv[]) {
  // Check for correct number of parameters
  if (argc != 3) {
    std::cout << "Expected 2 arguments (filename and subimage size(1-120))\n";
    return -1;
  }

  // Load image into mat and convert to grayscale
  Mat image = imread(argv[1], ImreadModes::IMREAD_GRAYSCALE);

  // Check if image was loaded
  if (!image.empty()) {
    // Display message that image was loaded
    std::cout << "Loaded image\n";

    // Get subpixel size
    int subImageSize = std::atoi(argv[2]);

    // Make sure subimage size is within bounds
    if (subImageSize < 1 || subImageSize > 120) {
      std::cout << "Subimage size out of bounds, expected 1-120\n";
      return -1;
    }

    // Convert image to a perfect square
    image = standardizeImage(image, subImageSize);
    std::cout << "Standardized image\n";

    // Create tree
    Tree imageLibraryTree;

    // Load tree with subimages
    loadImagesIntoTree(&imageLibraryTree, subImageSize);
    std::cout << "Loaded tree\n";

    // Generate a mosaic
    image = makeMosaic(image, subImageSize, imageLibraryTree);
    std::cout << "Made a mosaic\n";

    // Display mosaic
    namedWindow("Results");
    imshow("Results", image);
    waitKey(0);

    // Save mosaic to file
    imwrite("result.jpg", image);

    return 0;
  }

  // If we get here, an error occured loading image
  std::cout << "Error occured loading image\n";
  return -1;
}
