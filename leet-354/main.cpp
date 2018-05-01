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

int lis(vector<int> & arr) {
	vector<int> stack;
	for (int elem : arr) {
		if (stack.empty() || stack.back() < elem) {
			stack.push_back(elem);
		}
		else if (binary_search(stack.begin(), stack.end(), elem)){
			auto upper = upper_bound(stack.begin(), stack.end(), elem);
			*upper = elem;
		}
	}
	return stack.size();
}

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
	if (envelopes.empty()) {
		return 0;
	}

	auto cmp = [](const pii & a, const pii & b) {
		return a.first < b.first || (a.first == b.first && a.second > b.second);
	};
	sort(envelopes.begin(), envelopes.end(), cmp);

	vector<int> heights;
	for (auto ii : envelopes) {
		heights.push_back(ii.second);
	}

	return lis(heights);
}

int main() {
	//vector<pair<int, int>> arg0 = {
	//	{ 5, 4 }, { 6, 4 }, { 6, 7 }, { 2, 3 }
	//};
	vector<pair<int, int>> arg0 = {{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}};
	cout << maxEnvelopes(arg0);

	cin.get();
}