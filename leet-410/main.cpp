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

int splitArray(vector<int>& nums, int m) {
	ll left = 0;
	ll right = 0;
	for (int num : nums) {
		left = max(left, static_cast<ll>(num));
		right += static_cast<ll>(num);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;
		
		int remain = m;
		int current = 0;
		bool isValid = true;
		for (int num : nums) {
			current += num;

			if (current > mid) {
				current = num;
				remain--;

				if (remain == 0) {
					isValid = false;
					break;
				}
			}
		}

		if (isValid) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

int main() {
	vector<int> nums = { 7, 2, 5, 10, 8 };
	cout << splitArray(nums, 2) << endl;
	cin.get();
}