#pragma once
#include <vector>
#include <opencv2/core/core.hpp>
#include "Utility.h"

class Tree {
private:
	class Node {
	private:
		int averagePixelIntensity;
	public:
		std::vector<cv::Mat> data;

		Node *left, *right;

		Node(const cv::Mat& img);

		~Node();

		void selfDestruct();

		void addImage(const cv::Mat&img, const int currentAve);

		std::vector<cv::Mat> getImages(const int intensity);

		int getAverage();
	};

	Node *root;

public:
	Tree(const cv::Mat& img);

	Tree(std::vector<cv::Mat> images);

	~Tree();

	void addImage(const cv::Mat& img);

	cv::Mat getImage(const int intensity);

	const Node* getRoot();
};

