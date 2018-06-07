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
typedef pair<int, int> pii;
typedef long long ll;

int numberOfArithmeticSlices(vector<int>& A) {
	int ret = 0;
	vector<map<int, int>> dp(A.size());

	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			ll diff = ll(A[i]) - ll(A[j]);

			// to avoid MLE
			if (diff > INT_MAX || diff < INT_MIN) {
				continue;
			}
			
			int d = int(diff);
			int cur = dp[i][d];
			int last = dp[j][d];
			
			// last is 0 when 2 elements, 1 when 3 elements, etc.
			ret += last;

			dp[i][d] = last + 1 + cur;
		}
	}

	return ret;
}

int main() {
	vector<int> arg0 = { 2, 4, 6, 8, 10 };
	cout << numberOfArithmeticSlices(arg0) << endl;
	cin.get();
}