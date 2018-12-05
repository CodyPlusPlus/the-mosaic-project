/* Node : The declaration of a Node object for Tree data structure
 *
 * Filename : Node.h
 * Author : Brady Pascoe
 *
 */

#pragma once
#include <opencv2/core/core.hpp>
#include <vector>

// Declaration of a Node class
class Node {
  // Private variable
 private:
  // The key : images average intensity
  int averagePixelIntensity;

  // Public varaiables and functions
 public:
  // A vector of images
  std::vector<cv::Mat> data;

  // Pointers to left and right children
  Node *left, *right;

  /* Node : Constructor
   *
   * precondition : img is greyscale and has been initialized
   * postcondition : Node's vector shall contain img
   * params:
   *     img : The image to add to Node's vector
   *
   */
  Node(const cv::Mat& img);

  /* ~Node : Destructor
   *
   * precondition : None
   * postcondition : vector shall be cleared and children deleted
   *
   */
  ~Node();

  /* selfDestruct : Deallocates all nodes
   *
   * precondition : None
   * postcondition : All nodes shall be deleted
   *
   */
  void selfDestruct();

  /* addImage : Adds given image to node with corresponding average intensity
   *
   * precondition : Node has a set average, img is greyscale and initialized
   * postcondition : img shall be added to correct node
   * params:
   *     img : The image to add to node
   *     currentAve : The average pixel intensity of img
   *
   */
  void addImage(const cv::Mat& img, const int currentAve);

  /* getImages : Returns a vector of images with close/matching intensity
   *
   * precondition : node has been initialized and intensity between 0-255
   * postcondition : a vector of images with close/matching intensity shall be
   * ret. params: intensity : The average intensity we are looking for
   *
   * return : a vector of images
   */
  std::vector<cv::Mat> getImages(const int intensity);

  /* getAverage : Returns the average pixel intensity (key) of node
   *
   * precondition : average has been set
   * postcondition : average pixel intensity of node shall be returned
   *
   * return : average pixel intensity
   */
  int getAverage();
};
