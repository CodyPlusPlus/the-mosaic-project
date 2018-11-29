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

	// create vector of tiles
	for (int tileR = 0; tileR < mosaic.rows; tileR += n)
	{
		for (int tileC = 0; tileC < mosaic.cols; tileC += n)
		{
			tiles.push_back(mosaic(cv::Rect(tileC, tileR, n, n)));
		}
	}

	// step through vector of tiles and fill with mean value
	for (int i = 0; i < tiles.size(); i++)
	{
		int avgIntensity = cv::mean(tiles[i])[0];
		cv::Mat retrievedTile;

		for (int r = 0; r < tiles[i].rows; r++)
		{
			for (int c = 0; c < tiles[i].cols; c++)
			{
				retrievedTile = subimages.getImage(avgIntensity);
				tiles[i].at<uchar>(r, c) = retrievedTile.at<uchar>(r, c); // TODO: replace this with image retrieval function
			}
		}
	}

	return(mosaic);
}
