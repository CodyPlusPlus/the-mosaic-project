/* imagePreProcess.h : Declaration of functions used to prepare images for
 *			 mosaicing
 *
 * Filename: imagePreProcess.h
 * Author: Aleksandr Golovin (golo314@uw.edu)
 * Date: 26 Nov. 2018
 *
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iomanip>
#include <string>

#include "Tree.h"

using namespace cv;

/* standardizeImage : Given an image, adjusts image dimesions so block factors
 * 			into them
 *
 * preconditions : image is initialized and block is greater than 0vand less
 * 			than 120
 * postcondition : the subimages will be able to factor perfectly into image
 * parameters:
 *    image : candiate mosaic image
 *    block : single dimension of square subimage
 *
 * returns : image into which subimages factor into
 */
Mat standardizeImage(Mat image, int block);

/* standardizeSize : Given an image dimension, adjusts it so factors blockSize
 * 			factors into it
 *
 * preconditions : imageDim is greater than 0 and blockSize is greater than 0
 * 			and less than 120
 * postcondition : the subimages size will factor perfectly into image dimension
 * parameters:
 *    imagDim : the dimension of image (row or col)
 *    blockSize : single dimension of square subimage
 *
 * returns : image dimension into which subimages factor into
 */
int standardizeSize(int imageDim, int blockSize);

/* loadImagesIntoTree : Given tree, load it with subimages
 *
 * preconditions : subimages exist in directory Emoji and have numeric names
 * postcondition : tree will be populated with subimages
 * parameters:
 *    imageTree : tree to populate with subimages
 *    block : single dimension of square subimage
 *
 */
void loadImagesIntoTree(Tree* imageTree, int block);

/* padWithZeros : Given a value, pad it with zeros
 *
 * preconditions : values is greater than 0 and precision is 4
 * postcondition : a string containing value padded with zeros will be returned
 * parameters:
 *    value : number to pad
 *    precision : number of digit that should exist
 *
 * returns : a string of size precision, with padding for values under 1000
 */
std::string padWithZeros(const int value, const unsigned precision);
