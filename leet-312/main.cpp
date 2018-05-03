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

int maxCoins(vector<int>& nums) {
	int N = nums.size();
	nums.insert(nums.begin(), 1);
	nums.insert(nums.end(), 1);

	vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
	for (int len = 1; len <= N; ++len) {
		for (int left = 1; left <= N - len + 1; ++left) {
			int right = left + len - 1;

			int maxSum = 0;
			for (int last = left; last <= right; ++last) {
				int sum = dp[left][last - 1] + dp[last + 1][right];
				sum += nums[left - 1] * nums[last] * nums[right + 1];
				maxSum = max(maxSum, sum);
			}
			dp[left][right] = maxSum;
		}
	}

	return dp[1][N];
}

int main() {
	vector<int> arg0 = { 9,76,64,21,97,60 };
	cout << maxCoins(arg0);

	cin.get();
}