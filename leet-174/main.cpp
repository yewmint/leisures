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

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	const int ROWS = dungeon.size();
	const int COLS = dungeon[0].size();

	const int ENDROW = ROWS - 1;
	const int ENDCOL = COLS - 1;

	vector<vector<int>> hp(ROWS, vector<int>(COLS, INT_MIN));

	hp[ENDROW][ENDCOL] = 1;

	for (int r = ENDROW - 1; r >= 0; --r) {
		hp[r][ENDCOL] = max(hp[r + 1][ENDCOL] - dungeon[r + 1][ENDCOL], 1);
	}

	for (int c = ENDCOL - 1; c >= 0; --c) {
		hp[ENDROW][c] = max(hp[ENDROW][c + 1] - dungeon[ENDROW][c + 1], 1);
	}

	for (int r = ENDROW - 1; r >= 0; --r) {
		for (int c = ENDCOL - 1; c >= 0; --c) {
			hp[r][c] = max(min(hp[r + 1][c] - dungeon[r + 1][c], hp[r][c + 1] - dungeon[r][c + 1]), 1);
		}
	}

	return max(hp[0][0] - dungeon[0][0], 1);
}

int main() {
	vector<vector<int>> arg0 = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
	cout << calculateMinimumHP(arg0) << endl;
	cin.get();
}