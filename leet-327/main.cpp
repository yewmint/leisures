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

int countRangeSum(vector<int>& nums, int lower, int upper) {
	Fenwick<int> fw(nums);
}

int main() {
	vector<int> arg0 = { -2, 5, -1 };
	cout << countRangeSum(arg0, -2, 2);

	cin.get();
}