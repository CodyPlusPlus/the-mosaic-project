/* imagePreProcess:
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

Mat standardizeImage(Mat image, int blocks);

void loadImagesIntoTree(Tree & imageTree, int blocks);

std::string to_zero_lead(const int value, const unsigned precision);
