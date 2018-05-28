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

bool canCross(vector<int>& stones) {
	if (stones[1] != 1) {
		return false;
	}

	if (stones.size() == 2) {
		return true;
	}

	unordered_map<int, set<int>> lastSteps({ { 1, { 1 } } });
	unordered_set<int> nums(stones.begin(), stones.end());
	set<int> open({ 1 });

	while (!open.empty()) {
		int num = *open.begin();
		open.erase(open.begin());

		auto lastStep = lastSteps[num];
		set<int> steps;
		for (int last : lastStep) {
			steps.insert(last);
			steps.insert(last + 1);

			if (last - 1 > 0) {
				steps.insert(last - 1);
			}
		}

		for (int step : steps) {
			if (nums.count(num + step) > 0) {
				int nextNum = num + step;
				if (nextNum == stones.back()) {
					return true;
				}

				lastSteps[nextNum].insert(step);
				open.insert(nextNum);
			}
		}
	}

	return false;
}

int main() {
	vector<int> stones = { 0,1,3,5,6,8,12,17 };
	//vector<int> stones = { 0,1,2,3,4,8,9,11 };

	cout << boolalpha << canCross(stones) << endl;
	cin.get();
}