#include <iostream>
#include "Tree.h"
#include "imagePreProcess.h"
#include "mosaic.h"

int main() {
  Mat image = cv::imread("test.jpg", cv::ImreadModes::IMREAD_GRAYSCALE);
  std::cout<<"Loaded image\n";

  image = standardizeImage(image, 10);
  std::cout<<"Standardized image\n";

  Tree imageLibraryTree;
  loadImagesIntoTree(imageLibraryTree, (image.rows / 10));
  std::cout<<"Loaded tree\n";

  image = makeMosaic(image, 10, imageLibraryTree);
  std::cout<<"Made a mosaic\n";

  namedWindow("Results");
  imshow("Results", image);
  waitKey(0);

  system("PAUSE");
}
