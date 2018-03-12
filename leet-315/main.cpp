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
#include "fenwick.h"

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

vector<int> countSmaller(vector<int>& nums) {
	if (nums.size() == 0) {
		return vector<int>();
	}

	int minNum = *min_element(nums.begin(), nums.end());
	for (auto & num : nums) {
		num -= minNum;
	}

	int maxNum = *max_element(nums.begin(), nums.end());
	Fenwick<int> fw(maxNum + 1);
	vector<int> revRet;

	for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
		fw.add(*it, 1);
		revRet.push_back(fw.sum(*it - 1));
	}

	return vector<int>(revRet.rbegin(), revRet.rend());
}

int main() {
	vector<int> arg0 = { -1 };
	auto ans = countSmaller(arg0);
	for (int num : ans) {
		cout << num << endl;
	}

	cin.get();
}