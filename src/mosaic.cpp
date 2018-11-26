// File: mosaic.cpp
// Author: Cody Stuck
// Description: Contains the function definition of makeMosaic()

#include "mosaic.h"

// makeMosaic: converts an image into a mosaic using a set of smaller images
// preconditions: the mosaic image and tile images should be square and grayscale, the dimensions of the mosaic image should be a multiple of the dimensions of the tile images
// postconditions: a new mat will be returned

cv::Mat makeMosaic(cv::Mat input, int n)
{
	cv::Mat mosaic(input.rows, input.cols, CV_8UC1);
	std::vector<cv::Mat> tiles;

	if (input.rows != input.cols && input.rows % n != 0)
	{
		throw std::exception("err");
	}

	// create vector of tiles
	for (int tileR = 0; tileR < input.rows; tileR += input.rows / n)
	{
		for (int tileC = 0; tileC < input.cols; tileC += input.cols / n)
		{
			tiles.push_back(input(cv::Rect(tileC, tileR, input.cols / n, input.rows / n)));
		}
	}

	// step through vector of tiles and fill with mean value
	for (int i = 0; i < tiles.size(); i++)
	{
		cv::Scalar avgIntensity = cv::mean(tiles[i]);
		
		for (int r = 0; r < tiles[i].rows; r++)
		{
			for (int c = 0; c < tiles[i].cols; c++)
			{
				tiles[i].at<uchar>(r, c) = avgIntensity[0]; // TODO: replace this with image retrieval function
			}
		}
	}

	return(input);
}