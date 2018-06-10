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

bool canForm(const string & word, const unordered_set<string> & elements) {
	if (elements.empty()) return false;

	vector<bool> formEndWith(word.size() + 1);
	
	formEndWith[0] = true;
	for (int i = 1; i <= word.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (formEndWith[j] && elements.count(word.substr(j, i - j)) > 0) {
				formEndWith[i] = true;
			}
		}
	}

	return formEndWith[word.size()];
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
	sort(
		words.begin(), 
		words.end(), 
		[](const string & a, const string & b) -> bool { return a.size() < b.size(); }
	);

	vector<string> ret;
	unordered_set<string> elements;
	for (const string & word : words) {
		if (canForm(word, elements)) {
			ret.push_back(word);
		}
		elements.insert(word);
	}


	return ret;
}

int main() {
	vector<string> arg0 = {
		"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
	};

	auto ans = findAllConcatenatedWordsInADict(arg0);
	for (auto line : ans) {
		cout << line << endl;
	}

	//set<string> t0 = { "dog", "cat", "got" };
	//string word = "doggot";
	//cout << boolalpha << canForm(word, t0);

	cin.get();
}