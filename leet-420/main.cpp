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

int strongPasswordChecker(string s) {
	int lengthFix = 0;
	if (s.size() < 6) {
		lengthFix = 6 - lengthFix;
	}
	else if (s.size() > 20) {
		lengthFix = 20 - lengthFix;
	}

	int varietyFix = 3;
	for (char ch : s) {
		if (ch >= '0' && ch <= '9') {
			varietyFix--;
			break;
		}
	}
	for (char ch : s) {
		if (ch >= 'a' && ch <= 'z') {
			varietyFix--;
			break;
		}
	}
	for (char ch : s) {
		if (ch >= 'A' && ch <= 'Z') {
			varietyFix--;
			break;
		}
	}

	int repeatFix = 0;
	char last = '\0';
	int repeat = 1;
	for (char ch : s) {
		if (ch == last && ++repeat == 3) {
			repeatFix = true;
		}
	}
}

int main() {
	cout << strongPasswordChecker("aaabbbccc") << endl;
	cin.get();
}