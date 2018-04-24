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

#define mp make_pair
typedef long long ll;

string reverse(const string & str) {
	return string(str.rbegin(), str.rend());
}

vector<vector<int>> palindromePairs(vector<string>& words) {
	map<string, int> wordMap;
	for (int i = 0; i < words.size(); ++i) {
		wordMap[reverse(words[i])] = i;
	}

	set<vector<int>> ret;
	for (int i = 0; i < words.size(); ++i) {
		const auto & word = words[i];

		for (int j = 0; j <= word.size(); ++j) {
			string left(word.begin(), word.begin() + j);
			string right(word.begin() + j, word.end());

			if (right == reverse(right) && wordMap.count(left) > 0 && i != wordMap[left]) {
				ret.insert(vector<int>({ i, wordMap[left] }));
			}

			if (left == reverse(left) && wordMap.count(right) > 0 && i != wordMap[right]) {
				ret.insert(vector<int>({ wordMap[right], i }));
			}
		}
	}

	return vector<vector<int>>(ret.begin(), ret.end());
}

int main() {
	vector<string> words = { "abcd", "dcba", "lls", "s", "sssll" };
	auto ans = palindromePairs(words);
	for (auto line : ans) {
		cout << line[0] << ", " << line[1] << endl;
	}

	cin.get();
}