
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

int calculate(string s) {
	vector<int> opts;
	vector<int> nums;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			int num = 0;
			for (; i < s.size() && s[i] >= '0' && s[i] <= '9'; ++i) {
				num *= 10;
				num += s[i] - '0';
			}
			--i;
			
			if (opts.size() > 0 && (opts.back() == '+' || opts.back() == '-')) {
				auto onum = nums.back();
				num = opts.back() == '+' ? num + onum : onum - num;
				nums.pop_back();
				opts.pop_back();
			}

			nums.push_back(num);
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
			opts.push_back(s[i]);
		}
		else if (s[i] == ')') {
			opts.pop_back();
			while (nums.size() > 1 && opts.size() > 0 && opts.back() != '(' && opts.back() != ')') {
				int a = nums.back();
				nums.pop_back();
				int b = nums.back();
				nums.pop_back();

				int num = opts.back() == '+' ? a + b : b - a;
				nums.push_back(num);
				opts.pop_back();
			}
		}
	}

	return nums.back();
}

int main() {
	cout << calculate(" (1+(4+5+2)-3)+(6+8)");
	cin.get();
}