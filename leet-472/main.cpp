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

class Solution {
public:

	template<typename T1, typename T2>
	T1 sc(T2 val) {
		return static_cast<T1>(val);
	}

	multiset<int> leftSet;
	multiset<int> rightSet;

	void insert(int val) {
		if (rightSet.empty() || val < *rightSet.begin()) {
			leftSet.insert(val);
		}
		else {
			rightSet.insert(val);
		}

		adjust();
	}

	void remove(int val) {
		if (rightSet.empty() || val < *rightSet.begin()) {
			auto pos = leftSet.find(val);
			leftSet.erase(pos);
		}
		else {
			auto pos = rightSet.find(val);
			rightSet.erase(pos);
		}

		adjust();
	}

	void adjust() {
		if (rightSet.size() > leftSet.size()) {
			int val = *rightSet.begin();
			rightSet.erase(rightSet.begin());
			leftSet.insert(val);
		}
		else if (leftSet.size() > rightSet.size() + 1) {
			int val = *leftSet.rbegin();
			leftSet.erase(next(leftSet.rbegin()).base());
			rightSet.insert(val);
		}
	}

	double getMedian() {
		if (leftSet.size() > rightSet.size()) {
			return *leftSet.rbegin();
		}
		else {
			return (sc<double>(*leftSet.rbegin()) + sc<double>(*rightSet.begin())) / 2.0;
		}
	}

	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty() || k == 0) {
			return {};
		}

		for (int i = 0; i < k - 1; ++i) {
			insert(nums[i]);
		}

		vector<double> ret;
		for (int i = k - 1; i < nums.size(); ++i) {
			insert(nums[i]);
			ret.push_back(getMedian());
			remove(nums[i - k + 1]);
		}

		return ret;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> nums2 = { 5, 2, 2, 7, 3, 7, 9, 0, 2, 3 };
	vector<int> nums3 = { 7,0,3,9,9,9,1,7,2,3 };

	auto ans = s.medianSlidingWindow(nums3, 6);
	for (auto num : ans) {
		cout << num << endl;
	}

	cin.get();
}