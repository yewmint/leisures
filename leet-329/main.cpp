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

#define mp make_pair
typedef long long ll;

struct TopoPoint {
	int row, col;
	int val;
	int inCnt;
	int len;
	TopoPoint() : row(-1), col(-1), val(-1), inCnt(0), len(1) {};
	TopoPoint(int row, int col, int val) : row(row), col(col), val(val), inCnt(0), len(1) {};
};

int longestIncreasingPath(vector<vector<int>>& matrix) {
	if (matrix.empty()) {
		return 0;
	}

	const int ROW = matrix.size();
	const int COL = matrix[0].size();

	int dirs[] = { -1, 0, 1, 0, -1 };
	vector<vector<TopoPoint>> mat(ROW, vector<TopoPoint>(COL));
	queue<TopoPoint> heads;

	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			TopoPoint pt(row, col, matrix[row][col]);

			for (int i = 0; i < 4; ++i) {
				int curRow = row + dirs[i];
				int curCol = col + dirs[i + 1];
				if (
					curRow >= 0 && curRow < ROW &&
					curCol >= 0 && curCol < COL &&
					matrix[row][col] > matrix[curRow][curCol]
					) {
					pt.inCnt++;
				}
			}

			mat[row][col] = pt;

			if (pt.inCnt == 0) {
				heads.push(pt);
			}
		}
	}

	int maxLen = 1;

	while (!heads.empty()) {
		auto pt = heads.front();
		heads.pop();

		int row = pt.row;
		int col = pt.col;

		//printf_s("row:%d, col:%d, val:%d, len:%d\n", row, col, pt.val, pt.len);

		maxLen = max(maxLen, pt.len);

		for (int i = 0; i < 4; ++i) {
			int curRow = row + dirs[i];
			int curCol = col + dirs[i + 1];
			if (curRow < 0 || curRow >= ROW ||
				curCol < 0 || curCol >= COL) {
				continue;
			}
			auto & otherPoint = mat[curRow][curCol];
			if (pt.val < otherPoint.val) {
				otherPoint.inCnt--;
				otherPoint.len = max(otherPoint.len, pt.len + 1);
				if (otherPoint.inCnt == 0) {
					heads.push(otherPoint);
				}
			}
		}
	}

	return maxLen;
}

int main() {
	//vector<vector<int>> arg0 = {
	//	{9,9,4},
	//	{6,6,8},
	//	{2,1,1}
	//};
	vector<vector<int>> arg0 = {
		{3,4,5},
		{3,2,6},
		{2,2,1}
	};
	cout << longestIncreasingPath(arg0);

	cin.get();
}