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

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	list<int> maxNums;
	vector<int> ans;

	for (int i = 0; i < nums.size(); ++i) {
		while (!maxNums.empty() && maxNums.back() < nums[i]) maxNums.pop_back();
		maxNums.push_back(nums[i]);
		if (i >= k - 1) {
			ans.push_back(maxNums.front());
			if (nums[i - k + 1] == maxNums.front()) maxNums.pop_front();
		}
	}

	return ans;
}

int main() {
	vector<int> arg0 = { 1,3,-1,-3,5,3,6,7 };
	auto ans = maxSlidingWindow(arg0, 3);
	for (auto num : ans) {
		cout << num << endl;
	}
	cin.get();
}