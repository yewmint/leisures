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

struct NumIt {
	int num;
	list<int>::iterator it;
	NumIt(int num, list<int>::iterator it) : num(num), it(it) {};
};

auto cmp = [](NumIt &a, NumIt &b) {
	return a.num > b.num;
};

int maxCoins(vector<int>& nums) {
	int ret = 0;
	list<int> numbers;
	priority_queue<NumIt, vector<NumIt>, decltype(cmp)> heap(cmp);

	for (auto num : nums) {
		numbers.push_back(num);
		heap.push(NumIt(num, --numbers.end()));
	}

	while (!heap.empty()) {
		auto it = heap.top().it;
		heap.pop();

		int a = 0;
		int b = 0;
		int c = 0;
	}

	return ret;
}

int main() {
	vector<int> arg0 = { 3, 1, 5, 8 };
	cout << maxCoins(arg0) << endl;
	cin.get();
}