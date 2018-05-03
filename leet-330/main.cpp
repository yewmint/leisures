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
typedef long long ll;

int minPatches(vector<int>& nums, int n) {
	ll missedNum = 1;
	int added = 0;
	int i = 0;

	while (missedNum <= n) {
		if (i < nums.size() && nums[i] <= missedNum) {
			missedNum += nums[i++];
		}
		else {
			missedNum += missedNum;
			added++;
		}
	}

	return added;
}

int main() {
	vector<int> arg0 = { 1, 3 };
	cout << minPatches(arg0, 6);

	cin.get();
}