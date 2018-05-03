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

string rev(string & s) {
	reverse(s.begin(), s.end());
	for (char & ch : s) {
		if (ch == '(') ch = ')';
		else if (ch == ')') ch = '(';
	}
	return s;
}

vector<string> removeInvalidParentheses(string s) {
	set<string> ans;
	ans.insert("");
	int level = 0;

	for (char ch : s) {
		set<string> prev;
		prev.swap(ans);
		for (auto & line : prev) {
			string tmp(line);
			tmp.push_back(ch);
			ans.insert(tmp);
		}

		if (ch == ')') {
			level--;
			if (level < 0) {
				level = 0;
				set<string> pp;
				pp.swap(ans);

				for (auto & line : pp) {
					for (auto idx = line.find(')'); idx < line.size(); idx = line.find(')', idx + 1)) {
						string tmp(line);
						tmp.erase(idx, 1);
						ans.insert(tmp);
					}
				}
			}
		}
		else {
			if (ch == '(') level++;
		}
	}

	//while (level--) {
	//	set<string> pp;
	//	pp.swap(ans);

	//	for (auto & line : pp) {
	//		for (auto idx = line.find('('); idx < line.size(); idx = line.find('(', idx + 1)) {
	//			string tmp(line);
	//			tmp.erase(idx, 1);
	//			ans.insert(tmp);
	//		}
	//	}
	//}

	vector<string> ret;

	if (level > 0) {
		for (auto line : ans) {
			auto revLine = rev(line);
			auto subanses = removeInvalidParentheses(revLine);
			for (auto & subans : subanses) {
				ret.push_back(rev(subans));
			}
		}
	}
	else {
		ret.assign(ans.begin(), ans.end());
	}

	return ret;
}

int main() {
	//auto ans = removeInvalidParentheses("()(a))()");
	//auto ans = removeInvalidParentheses(")(f");
	//auto ans = removeInvalidParentheses(")d))");
	auto ans = removeInvalidParentheses(")()(");
	for (auto line : ans) {
		cout << line << endl;
	}
	cin.get();
}