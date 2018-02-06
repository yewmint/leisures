#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

unordered_map<string, vector<string>> cache;

vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
	if (cache.count(s) > 0) return cache[s];

	vector<string> ans;
	if (wordDict.count(s) > 0) {
		ans.push_back(s);
	}

	for (int i = 1; i < s.size(); ++i) {
		string word = s.substr(0, i);

		if (wordDict.count(word) > 0) {
			string left = s.substr(i);
			vector<string> innerAns = wordBreak(left, wordDict);

			for (string &ians : innerAns) {
				ans.push_back(word + " " + ians);
			}
		}
	}

	cache[s] = ans;
	return ans;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string> dict;
	for (auto &word : wordDict) {
		dict.insert(word);
	}

	return wordBreak(s, dict);
}

int main() {
	string arg0 = "catsanddog";
	vector<string> arg1 = { "cat", "cats", "and", "sand", "dog" };
	auto ans = wordBreak(arg0, arg1);
	for (auto line : ans) {
		cout << line << endl;
	}
	cin.get();
}