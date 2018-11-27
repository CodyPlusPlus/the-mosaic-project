// File: mosaic.cpp
// Author: Cody Stuck
// Description: Contains the function definition of makeMosaic()

#include "mosaic.h"

// makeMosaic: converts an image into a mosaic using a set of smaller images
// preconditions: the mosaic image and tile images should be square and grayscale, the dimensions of the mosaic image should be a multiple of the dimensions of the tile images
// postconditions: a new mat will be returned
cv::Mat makeMosaic(const cv::Mat &input, int n, const Tree &subimages)
{
	cv::Mat mosaic = input.clone();
	std::vector<cv::Mat> tiles;

	if (mosaic.rows != mosaic.cols && mosaic.rows % n != 0)
	{
		throw std::exception("err: cannot divide dimensions into tiles evenly!");
	}

	// create vector of tiles
	for (int tileR = 0; tileR < mosaic.rows; tileR += mosaic.rows / n)
	{
		for (int tileC = 0; tileC < mosaic.cols; tileC += mosaic.cols / n)
		{
			tiles.push_back(mosaic(cv::Rect(tileC, tileR, mosaic.cols / n, mosaic.rows / n)));
		}
	}

	// step through vector of tiles and fill with mean value
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i] = subimages.getImage(static_cast<int>(cv::mean(tiles[i])[0])).clone(); // fill each tile with the appropriate subimage

		//cv::Scalar avgIntensity = cv::mean(tiles[i]);

		//for (int r = 0; r < tiles[i].rows; r++)
		//{
		//	for (int c = 0; c < tiles[i].cols; c++)
		//	{
		//		tiles[i].at<uchar>(r, c) = avgIntensity[0]; // TODO: replace this with image retrieval function
		//	}
		//}
	}

	return(mosaic);
}