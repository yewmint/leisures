#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

struct SegTreeNode {
	int l, r;
	int overlay;
	SegTreeNode() : l(-1), r(-1), overlay(-1) {};
	SegTreeNode(int l, int r, int overlay) : l(l), r(r), overlay(overlay) {};
};

void buildTreeNode(SegTreeNode* tree, int l, int r, int pos) {
	auto node = tree[pos];
	node.l = l;
	node.r = r;
	node.overlay = 0;

	if (l < r) {
		int m = (l + r) / 2;
		buildTreeNode(tree, l, m, pos * 2 + 1);
		buildTreeNode(tree, m + 1, r, pos * 2 + 2);
	}
}

SegTreeNode* buildTree(int l, int r) {
	int n = r - l + 1;
	SegTreeNode *tree = new SegTreeNode[4 * n];
	buildTreeNode(tree, l, r, 0);
}

void query() {
	// TODO: How to query number of rects on given segmen?
}

struct Segment {
	int l, r, y;
	bool isEnter;
	Segment(int l, int r, int y, bool isEnter) : l(l), r(r), y(y), isEnter(isEnter) {};
};

auto cmp = [](Segment a, Segment b) { return a.y < b.y; };

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		int min = 0;
		int max = 0;
		priority_queue<Segment, vector<Segment>, decltype(cmp)> segs;
		while (N--) {
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;

			if (x0 < min) {
				min = x0;
			}
			if (x1 > max) {
				max = x1;
			}

			Segment segA(x0, x1, y0, true);
			Segment segB(x0, x1, y1, false);
			segs.push(segA);
			segs.push(segB);
		}


	}
}