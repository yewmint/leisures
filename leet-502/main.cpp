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

int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
	vector<pii> projects;
	for (int i = 0; i < Profits.size(); ++i) {
		projects.push_back(mp(Capital[i], Profits[i]));
	}
	sort(projects.rbegin(), projects.rend());

	priority_queue<int> availableProfits;
	while (k--) {
		while (projects.size() > 0 && projects.back().first <= W) {
			availableProfits.push(projects.back().second);
			projects.pop_back();
		}

		if (availableProfits.empty()) {
			break;
		}

		W += availableProfits.top();
		availableProfits.pop();
	}

	return W;
}

int main() {
	vector<int> arg0 = { 1, 2, 3 };
	vector<int> arg1 = { 0, 1, 1 };
	cout << findMaximizedCapital(2, 0, arg0, arg1) << endl;
	cin.get();
}