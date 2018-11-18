#pragma once
#include <vector>
#include <opencv2/core/core.hpp>
#include "Utility.hpp"

class Tree {
private:
	class Node {
	private:
		int averagePixelIntensity;
	public:
		std::vector<cv::Mat> data;

		Node *left, *right;

		Node(const cv::Mat& img) {
			averagePixelIntensity = getAvergePixelIntensity(img);
			data.push_back(img);
			left = 0;
			right = 0;
		}

		~Node() {
			delete left;
			delete right;
		}

		void selfDestruct() {
			if (left) {
				left->selfDestruct();
				delete left;
			}

			if (right) {
				right->selfDestruct();
				delete right;
			}
		}

		void addImage(const cv::Mat& img, const int currentAve) {
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

			data.push_back(img);
		}

		std::vector<cv::Mat> getImages(const int intensity) {
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

		int getAverage() {
			return averagePixelIntensity;
		}
	};

	Node *root;

public:
	Tree(const cv::Mat& img) {
		root = new Node(img);
	}
	Tree(std::vector<cv::Mat> images) {
		for (std::size_t i = 0; i < images.size(); i++) {
			addImage(images[i]);
		}
	}
	~Tree() {
		if (root) {
			root->selfDestruct();
			delete root;
		}
	}

	void addImage(const cv::Mat& img) {
		root->addImage(img, getAvergePixelIntensity(img));
	}

	std::vector<cv::Mat> getImages(const int intensity) {
		return root->getImages(intensity);
	}
};
