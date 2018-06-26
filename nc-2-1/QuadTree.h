#ifndef __H_QUAD_TREE__
#define __H_QUAD_TREE__

#include <memory>
#include "geometry.h"

struct Node {
	Rect area;
	int val = 0;
	std::vector<std::shared_ptr<Node>> children;
	Node(Rect area) : area(area) {};
};

std::shared_ptr<Node> makeQuadTree(Rect area) {
	return std::shared_ptr<Node>(new Node(area));
}

void add(std::shared_ptr<Node> node, Point pt, int val) {
	node->val += val;

	//cout << node->area.leftBottom.x << ", " << node->area.leftBottom.y;
	//cout << "; ";
	//cout << node->area.rightTop.x << ", " << node->area.rightTop.y;
	//cout << std::endl;

	if (node->children.empty() && canSplit(node->area)) {
		const Rect & area = node->area;
		auto apartAreas = split(area);
		for (auto apartArea : apartAreas) {
			std::shared_ptr<Node> ptr(new Node(apartArea));
			node->children.push_back(ptr);
		}
	}

	for (auto child : node->children) {
		if (contains(child->area, pt)) {
			add(child, pt, val);
			break;
		}
	}
}

int sum(std::shared_ptr<Node> node, Rect rect) {
	if (node->area == rect) {
		return node->val;
	}

	int ret = 0;
	for (auto child : node->children) {
		if (isOverlay(child->area, rect)) {
			ret += sum(child, overlay(child->area, rect));
		}
	}

	return ret;
}

#endif
