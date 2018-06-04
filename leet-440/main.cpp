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

int getGap(int n, int a, int b) {
	int gap = 0;
	while (a <= n) {
		gap += min(b, n + 1) - a;
		a *= 10;
		b *= 10;
	}
	return gap;
}

int findKthNumber(int n, int k) {
	int cur = 1;
	int remain = k - 1;
	while (remain > 0) {
		int gap = 0;
		if (cur + 1 <= n) gap = getGap(n, cur, cur + 1);

		if (cur + 1 <= n && gap <= remain) {
			remain -= gap;
			cur++;
		}
		else {
			cur *= 10;
			remain--;
		}
	}
	return cur;
}

int main() {
	cout << findKthNumber(2, 2) << endl;

	cin.get();
}