
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

#define mp make_pair

typedef pair<int, vector<int>> HeightRect;

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
	vector<pair<int, int>> ans;
	map<int, vector<vector<int>>> seq;
	set<HeightRect, greater<HeightRect>> heights;
	heights.insert(mp(0, vector<int>()));

	for (auto building : buildings) {
		seq[building[0]].push_back(building);
		seq[building[1]].push_back(building);
	}

	int lastHeight = 0;
	for (auto vertRects : seq) {
		auto vertical = vertRects.first;
		auto rects = vertRects.second;

		for (auto rect : rects) {
			if (vertical == rect[0]) {
				heights.insert(mp(rect[2], rect));
			}
			else {
				heights.erase(mp(rect[2], rect));
			}
		}

		int maxHeight = heights.begin()->first;
		if (maxHeight != lastHeight) {
			ans.push_back(mp(vertical, maxHeight));
		}
		lastHeight = maxHeight;
	}

	return ans;
}

int main() {
	//vector<vector<int>> arg0 = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
	vector<vector<int>> arg0 = { {0, 2, 3}, {2, 5 ,3} };
	auto ans = getSkyline(arg0);
	for (auto p : ans) {
		cout << p.first << "," << p.second << endl;
	}
	cin.get();
}