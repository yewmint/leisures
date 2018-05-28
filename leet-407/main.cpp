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
typedef pair<int, int> Position;
typedef pair<int, Position> ValPos;

#define OPEN 0
#define INQUEUE 1
#define CLOSE 2

int trapRainWater(vector<vector<int>>& heightMap) {
	if (heightMap.size() < 3) return 0;
	if (heightMap[0].size() < 3) return 0;

	int ROWS = heightMap.size();
	int COLS = heightMap[0].size();
	priority_queue<ValPos, vector<ValPos>, greater<ValPos>> heap;
	vector<vector<int>> states(ROWS, vector<int>(COLS, OPEN));

	for (int i = 0; i < COLS - 1; ++i) {
		heap.push(ValPos({ heightMap[0][i], { 0, i } }));
		states[0][i] = INQUEUE;
		heap.push(ValPos({ heightMap[ROWS - 1][i + 1], { ROWS - 1, i + 1 } }));
		states[ROWS - 1][i + 1] = INQUEUE;
	}

	for (int i = 0; i < ROWS - 1; ++i) {
		heap.push(ValPos({ heightMap[i + 1][0], { i + 1, 0 } }));
		states[i + 1][0] = INQUEUE;
		heap.push(ValPos({ heightMap[i][COLS - 1], { i, COLS - 1 } }));
		states[i][COLS - 1] = INQUEUE;
	}

	int water = 0;
	int maxBarrier = 0;
	int remain = (ROWS - 2) * (COLS - 2);
	while (remain > 0) {
		auto lowest = heap.top();
		heap.pop();
		
		int lowVal = lowest.first;
		auto pos = lowest.second;

		states[pos.first][pos.second] = CLOSE;
		maxBarrier = max(maxBarrier, lowVal);

		int dirs[] = { 1, 0, -1, 0, 1 };
		for (int i = 0; i < 4; ++i) {
			int row = pos.first + dirs[i];
			int col = pos.second + dirs[i + 1];

			if (row >= 0 && row < ROWS && col >= 0 && col < COLS &&
				states[row][col] == OPEN) {
				water += max(0, maxBarrier - heightMap[row][col]);
				heap.push({ heightMap[row][col], { row, col } });
				states[row][col] = INQUEUE;
				remain--;
			}
		}
	}

	return water;
}

int main() {
	vector<vector<int>> heightMap = {
		{1, 4, 3, 1, 3, 2},
		{3, 2, 1, 3, 2, 4},
		{2, 3, 3, 2, 3, 1}
	};

	cout << trapRainWater(heightMap) << endl;
	cin.get();
}