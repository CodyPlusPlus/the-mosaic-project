#include "Node.h"

Node::Node(const cv::Mat& img) {
	averagePixelIntensity = cv::mean(img)[0];
	data.push_back(img);
	left = 0;
	right = 0;
}

Node::~Node() {
	delete left;
	delete right;
}

void Node::selfDestruct() {
	if (left) {
		left->selfDestruct();
		delete left;
	}

	if (right) {
		right->selfDestruct();
		delete right;
	}
}

void Node::addImage(const cv::Mat& img, const int currentAve) {
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

std::vector<cv::Mat> Node::getImages(const int intensity) {
	if (intensity < averagePixelIntensity) {
		if (left == 0)
			return data;
		else
			return left->getImages(intensity);
	}
	else if (intensity > averagePixelIntensity) {
		if (right == 0)
			return data;
		else
			return right->getImages(intensity);
	}
	else {
		return data;
	}
}

int Node::getAverage() {
	return averagePixelIntensity;
}
