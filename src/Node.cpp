/* Node : The implementation of a Node object for Tree data structure
 *
 * Filename : Node.cpp
 * Author : Brady Pascoe
 *
 */

#include "Node.h"

// Implementation : Constructor with img
Node::Node(const cv::Mat& img) {
  // Set the key to images avg. intensity
  averagePixelIntensity = cv::mean(img)[0];

  // Add image to vector
  data.push_back(img);

  // Set both children to nullptr
  left = nullptr;
  right = nullptr;
}

// Implementation : Destructor
Node::~Node() {
  // Clear the images from vector
  data.clear();

  // Delete both children
  delete left;
  left = nullptr;
  delete right;
  right = nullptr;
}

// Implementation : selfDestruct
void Node::selfDestruct() {
  // If left child not nullptr
  if (left != nullptr) {
    // Delete all of left childs children
    left->selfDestruct();

    // Delete left child
    delete left;
    left = nullptr;
  }

  // If right child not nullptr
  if (right != nullptr) {
    // Delete all of right childs children
    right->selfDestruct();

    // Delete right child
    delete right;
    right = nullptr;
  }
}

// Implementation : addImage function
void Node::addImage(const cv::Mat& img, const int currentAve) {
  // If image average intensity less then value in current node
  if (currentAve < averagePixelIntensity) {
    // If a left child exists, go left
    if (left != nullptr) {
      left->addImage(img, currentAve);
    }
    // Else add a new left child
    else {
      left = new Node(img);
    }
  }
  // If image average intensity greater then value in current node
  else if (currentAve > averagePixelIntensity) {
    // If right child exists, go right
    if (right != nullptr) {
      right->addImage(img, currentAve);
    }
    // Else, add new right child
    else {
      right = new Node(img);
    }
  }
  // currentAve == averagePixelIntensity
  else {
    // Add image to node
    data.push_back(img);
  }
}

// Implementation : getImages
std::vector<cv::Mat> Node::getImages(const int intensity) {
  // If given intensity less than current node intensity
  if (intensity < averagePixelIntensity) {
    // If left child does NOT exists, return data of current node
    if (left == nullptr)
      return data;
    else
      return left->getImages(intensity);
  }
  // If given intensity greater than current node intenstiy
  else if (intensity > averagePixelIntensity) {
    // If right child does NOT exist, return data of current node
    if (right == nullptr)
      return data;
    else
      return right->getImages(intensity);
  }
  // If given intensity == current node intensity
  else {
    // Return vector of images
    return data;
  }
}

// Implementation : getAverage
int Node::getAverage() {
  // Return key of node
  return averagePixelIntensity;
}
