/* Tree : The implementation of the BST datastructure
 *
 * Filename : Tree.cpp
 * Author : Brady Pascoe
 *
 */

#include "Tree.h"

// Implementation : default constructor
Tree::Tree() {
  // Set root to nullptr
  root = nullptr;
}

// Implementation : constructor with image
Tree::Tree(const cv::Mat& img) {
  // Set root to new Node created by Node constructor
  root = new Node(img);
}

// Implementation : constructor with vector of images
Tree::Tree(std::vector<cv::Mat> images) {
  // For the number of images in vector
  for (std::size_t i = 0; i < images.size(); i++) {
    // Call the add function passing image
    addImage(images[i]);
  }
}

// Implementation : destructor
Tree::~Tree() {
  // If root not nullptr
  if (root) {
    // Call node self destruct function
    root->selfDestruct();

    // delete root
    delete root;

    // Handle dangling pointer
    root = nullptr;
  }
}

// Implementation : addimage function with given image
void Tree::addImage(const cv::Mat& img) {
  // If root is nullptr, create a new node
  if (root == nullptr) {
    root = new Node(img);
  }
  // Else, call node's addimage with image and avg. intensity
  else {
    root->addImage(img, cv::mean(img)[0]);
  }
}

// Implementation :
cv::Mat Tree::getImage(const int intensity) const {
  // If root not nullptr
  if (root != nullptr) {
    // Get the vector of images with given intensity
    std::vector<cv::Mat>& outVec = root->getImages(intensity);

    // If vector contains images
    if (outVec.size() > 0) {
      // Get first image in vector
      cv::Mat out = outVec[0];

      // remove the out and push it to the back
      outVec.erase(outVec.begin());
      outVec.push_back(out);

	  // Return the image
	  return out;
    }
    // Vector is empty, return blank image
    else {
      return cv::Mat();
    }
  }
  // Root is nullptr, return blank image
  else {
    return cv::Mat();  // Empty image for error handling
  }
}

// Implementation : getRoot function
const Node* Tree::getRoot() {
  // Return root pointer
  return root;
}
