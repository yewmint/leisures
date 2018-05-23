#include <iostream>
#include <string>
#include <sstream>
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
#include <numeric>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

bool isRectangleCover(vector<vector<int>>& rectangles) {
	int area = 0;
	set<pii> corners;

	int minX = INT_MAX;
	int minY = INT_MAX;
	int maxX = INT_MIN;
	int maxY = INT_MIN;

	for (auto rect : rectangles) {
		vector<pii> cors = {
			{ rect[0], rect[1] },
			{ rect[0], rect[3] },
			{ rect[2], rect[1] },
			{ rect[2], rect[3] },
		};

		for (auto cor : cors) {
			if (corners.count(cor) > 0) {
				corners.erase(cor);
			}
			else {
				corners.insert(cor);
			}
		}

		minX = min(minX, rect[0]);
		minY = min(minY, rect[1]);
		maxX = max(maxX, rect[2]);
		maxY = max(maxY, rect[3]);

		area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
	}

	if (corners.size() != 4 ||
		corners.find({ minX, minY }) == corners.end() ||
		corners.find({ minX, maxY }) == corners.end() ||
		corners.find({ maxX, minY }) == corners.end() ||
		corners.find({ maxX, maxY }) == corners.end() ||
		area != (maxX - minX) * (maxY - minY)
	) {
		return false;
	}

	return true;
}

int main() {
	//vector<vector<int>> rectangles = {
	//	{1, 1, 3, 3},
	//	{3, 1, 4, 2},
	//	{1, 3, 2, 4},
	//	{2, 2, 4, 4}
	//};

	vector<vector<int>> rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};

	cout << boolalpha << isRectangleCover(rectangles) << endl;
	cin.get();
}