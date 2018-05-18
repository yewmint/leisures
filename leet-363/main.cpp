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

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
	int ROWS = matrix.size();
	int COLS = matrix[0].size();
	int ret = INT_MIN;

	for (int l = 0; l < COLS; ++l) {
		vector<int> sums(ROWS, 0);

		for (int r = l; r < COLS; ++r) {
			set<int> sumSet({ 0 });
			int curSum = 0;

			for (int i = 0; i < ROWS; ++i) {
				sums[i] += matrix[i][r];
				curSum += sums[i];

				int tmpk = curSum - k;
				auto it = sumSet.lower_bound(tmpk);
				if (it != sumSet.end()) {
					ret = max(ret, curSum - *it);
				}

				sumSet.insert(curSum);
			}
		}
	}

	return ret;
}

int main() {
	vector<vector<int>> arg0 = {
		{ 5, -4, -3, 4 },
		{ -3, -4, 4, 5 },
		{ 5, 1, 5, -4 }
	};

	cout << maxSumSubmatrix(arg0, 8);
	cin.get();
}