#include "Tree.h"

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

const Node* Tree::getRoot() {
	return root;
}
