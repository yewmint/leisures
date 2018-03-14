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
#include "fenwick.h"

using namespace std;
using namespace yewmint;

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

string removeDuplicateLetters(string s) {
	vector<int> cnts(26, 0);
	for (char ch : s) {
		cnts[ch - 'a']++;
	}

	int len = 0;
	for (int cnt : cnts) {
		if (cnt > 0) {
			++len;
		}
	}

	vector<bool> inRet(26, false);
	string ret;
	for (int i = 0; i < s.size(); ++i) {
		char ch = s[i];

		while (
			!inRet[ch - 'a'] &&
			!ret.empty() &&
			ret.back() > ch &&
			cnts[ret.back() - 'a'] > 0 &&
			s.size() - i >= len - ret.size()
			) {
			inRet[ret.back() - 'a'] = false;
			ret.pop_back();
		}

		if (!inRet[ch - 'a']) {
			inRet[ch - 'a'] = true;
			ret.push_back(ch);
		}

		cnts[ch - 'a']--;
	}

	return ret;
}

int main() {
	cout << removeDuplicateLetters("bbcaac") << endl;
	cout << removeDuplicateLetters("cbacdcbc") << endl;
	cout << removeDuplicateLetters("bcabc") << endl;
	cin.get();
}