#include "Node.h"

Node::Node(const cv::Mat& img) {
	averagePixelIntensity = cv::mean(img)[0];
	data.push_back(img);
	left = nullptr;
	right = nullptr;
}

Node::~Node() {
	data.clear();
	delete left;
	left = nullptr;
	delete right;
	right = nullptr;
}

void Node::selfDestruct() {
	if (left != nullptr) {
		left->selfDestruct();
		delete left;
		left = nullptr;
	}

	if (right != nullptr) {
		right->selfDestruct();
		delete right;
		right = nullptr;
	}
}

void Node::addImage(const cv::Mat& img, const int currentAve) {
	if (currentAve < averagePixelIntensity) {
		if (left != nullptr) {
			left->addImage(img, currentAve);
		}
		else {
			left = new Node(img);
		}
	}
	else if (currentAve > averagePixelIntensity) {
		if (right != nullptr) {
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
		if (left == nullptr)
			return data;
		else
			return left->getImages(intensity);
	}
	else if (intensity > averagePixelIntensity) {
		if (right == nullptr)
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
