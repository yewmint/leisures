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
#include "binary-search.h"

using namespace std;
using namespace yewmint;

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

int countSubRange(vector<int>& nums, int lower, int upper, int l, int r) {
	if (l == r) {
		return nums[l] >= lower && nums[l] <= upper ? 1 : 0;
	}

	int m = (l + r) / 2;
	vector<ll> sums(r - m, 0);
	ll sum = 0;
	for (int i = m + 1; i <= r; ++i) {
		sum += nums[i];
		sums[i - m - 1] = sum;
	}

	sort(sums.begin(), sums.end());

	sum = 0;
	int cnt = 0;
	for (int i = m; i >= l; --i) {
		sum += nums[i];
		cnt += binarySearchUpper(sums, upper - sum + 0.5) - binarySearchUpper(sums, lower - sum - 0.5);
	}

	return countSubRange(nums, lower, upper, l, m) + countSubRange(nums, lower, upper, m + 1, r) + cnt;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
	if (nums.empty()) {
		return 0;
	}
	return countSubRange(nums, lower, upper, 0, nums.size() - 1);
}

int main() {
	vector<int> arg0 = { -2, 5, -1 };
	cout << countRangeSum(arg0, -2, 2);

	cin.get();
}