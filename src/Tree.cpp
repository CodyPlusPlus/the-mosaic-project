#pragma once
#include "Tree.h"

// Node
Tree::Node::Node(const cv::Mat& img) {
	averagePixelIntensity = getAvergePixelIntensity(img);
	data.push_back(img);
	left = 0;
	right = 0;
}

Tree::Node::~Node() {
	delete left;
	delete right;
}

void Tree::Node::selfDestruct() {
	if (left) {
		left->selfDestruct();
		delete left;
	}

	if (right) {
		right->selfDestruct();
		delete right;
	}
}

void Tree::Node::addImage(const cv::Mat& img, const int currentAve) {
	if (currentAve < averagePixelIntensity) {
		if (left) {
			left->addImage(img, currentAve);
		}
		else {
			left = new Node(img);
		}
	}
	else if (currentAve > averagePixelIntensity) {
		if (right) {
			right->addImage(img, currentAve);
		}
		else {
			right = new Node(img);
		}
	}
	else { // currentAve == averagePixelIntensity
		data.push_back(img);
	}
}

std::vector<cv::Mat> Tree::Node::getImages(const int intensity) {
	if (intensity < averagePixelIntensity) {
		return left->getImages(intensity);
	}
	else if (intensity > averagePixelIntensity) {
		return right->getImages(intensity);
	}
	else {
		return data;
	}
}

int Tree::Node::getAverage() {
	return averagePixelIntensity;
}

// Tree
Tree::Tree(const cv::Mat& img) {
	root = new Node(img);
}
Tree::Tree(std::vector<cv::Mat> images) {
	for (std::size_t i = 0; i < images.size(); i++) {
		addImage(images[i]);
	}
}
Tree::~Tree() {
	if (root) {
		root->selfDestruct();
		delete root;
	}
}

void Tree::addImage(const cv::Mat& img) {
	root->addImage(img, getAvergePixelIntensity(img));
}

cv::Mat Tree::getImage(const int intensity) {
	if (root != 0) {
		std::vector<cv::Mat> outVec = root->getImages(intensity);
		if (outVec.size() > 0) {
			cv::Mat out = outVec[0];
			// remove the out and push it to the back
			outVec.erase(outVec.begin());
			outVec.push_back(out);
			return out;
		}
		else {
			return cv::Mat();
		}
	}
	else {
		return cv::Mat(); // Empty image for error handling
	}

}

const Tree::Node* Tree::getRoot() {
	return root;
}
