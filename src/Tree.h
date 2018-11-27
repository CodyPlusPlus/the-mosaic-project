#pragma once
#include <vector>
#include <opencv2/core/core.hpp>
#include "Utility.h"
#include "Node.h"

class Tree {
private:
	Node *root;

public:
	Tree(const cv::Mat& img);

	Tree(std::vector<cv::Mat> images);

	~Tree();

	void addImage(const cv::Mat& img);

	cv::Mat getImage(const int intensity);

	const Node* getRoot();
};

