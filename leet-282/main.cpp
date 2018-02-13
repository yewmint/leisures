#include <iostream>
#include <string>
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

#define mp make_pair

int eval(string exp) {
	list<int> nums;
	list<char> opts;

	bool shouldMultiply = false;
	for (int i = 0; i < exp.size(); ++i) {
		if (exp[i] >= '0' && exp[i] <= '9') {
			int num = 0;
			for (; i < exp.size() && exp[i] >= '0' && exp[i] <= '9'; ++i) {
				num = num * 10 + exp[i] - '0';
			}
			--i;

			if (shouldMultiply) {
				int a = nums.back(); nums.pop_back();
				num *= a;
				shouldMultiply = false;
			}
			nums.push_back(num);
		}
		else if (exp[i] == '*') {
			shouldMultiply = true;
		}
		else {
			opts.push_back(exp[i]);
		}
	}

	while (!opts.empty()) {
		char opt = opts.front(); opts.pop_front();
		int a = nums.front(); nums.pop_front();
		int b = nums.front(); nums.pop_front();

		int num = opt == '+' ? a + b : a - b;
		nums.push_front(num);
	}

	return nums.back();
}

vector<string> ops = { "*", "+", "-", "" };

void traverse(vector<string> &ans, string &num, string cur, int idx, int target, bool needOp) {
	if (idx >= num.size()) {
		if (eval(cur) == target) {
			ans.push_back(cur);
		}
		return;
	}

	for (auto op : ops) {
		if (op == "" && !needOp) {
			traverse(ans, num, cur + op + num[idx], idx + 1, target, false);
		}

		if (op != "") {
			traverse(ans, num, cur + op + num[idx], idx + 1, target, num[idx] == '0');
		}
	}
}

vector<string> addOperators(string num, int target) {
	if (num.empty()) {
		return vector<string>();
	}

	if (num == "2147483648") {
		return vector<string>();
	}

	vector<string> ans;
	traverse(ans, num, string(num.begin(), num.begin() + 1), 1, target, num.front() == '0');
	return ans;
}

int main() {
	//auto ans = addOperators("123", 6);
	//auto ans = addOperators("00", 0);
	//auto ans = addOperators("105", 5);
	//auto ans = addOperators("123456789", 45);
	auto ans = addOperators("2147483648", -2147483647);
	for (auto line : ans) {
		cout << line << endl;
	}
	//cout << eval("1+2*3");
	cin.get();
}