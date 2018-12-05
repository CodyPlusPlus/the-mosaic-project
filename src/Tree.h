/* Tree : An declaration of the BST datastructure
 *
 * Filename : Tree.h
 * Author : Brady Pascoe
 *
 */

#pragma once
#include <opencv2/core/core.hpp>
#include <vector>
#include "Node.h"

// Declaration of the data structure class
class Tree {
  // Private variable
 private:
  Node* root;

  // Public functions
 public:
  /* Tree : Default constructor
   *
   * precondition : Node class has been implemented
   * postcondition : root shall point to nullptr
   */
  Tree();

  /* Tree : Constructor has sets root to point to Node with image
   *
   * precondition : Node class has been implement and node class can store Mat
   * postcondition : root shall point to Node with a vector containing img
   * params:
   *     img : The image to be added to Node
   */
  Tree(const cv::Mat& img);

  /* Tree : Constructor has sets root to point to Node a vector of images
   *
   * precondition : Node class has been implement and can store vector of images
   * postcondition : root shall point to Node with a vectors of images
   * params:
   *     images : The vector of images to be added to Node
   */
  Tree(std::vector<cv::Mat> images);

  /* ~Tree : Destructor
   *
   * precondition : none
   * postcondition : tree data structure shall be empty
   */
  ~Tree();

  /* addImage : Adds given image to correct Node
   *
   * precondition : img is greyscal and has been initialized
   * postcondition : Node with intensity matching that of image shall have img
   * params:
   *     img : The image to be added to Node
   */
  void addImage(const cv::Mat& img);

  /* getImage : Return an image from node with a close/matching intensity
   *
   * precondition : Tree has items in it and intensity between 0-255
   * postcondition : an image with close/matching intensity shall be returned
   * params:
   *     intensity : The desired image intensity
   *
   * return : image with close/matching intensity
   */
  cv::Mat getImage(const int intensity) const;

  /* getRoot : Return a const pointer to root
   *
   * precondition : None
   * postcondition : const pointer to root shall be returned
   *
   * return : const pointer to root
   */
  const Node* getRoot();
};
