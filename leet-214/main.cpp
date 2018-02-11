
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

vector<int> makeNext(string line) {
	if (line.size() <= 1) {
		return vector<int>(line.size(), -1);
	}

	vector<int> next(line.size(), -1);
	next[1] = 0;

	for (int i = 2; i < line.size(); ++i) {
		int j = i - 1;
		while (j > 0 && line[next[j]] != line[i - 1]) {
			j = next[j];
		}
		next[i] = next[j] + 1;
	}

	return next;
}

string shortestPalindrome(string s) {
	string reversed = s;
	reverse(reversed.begin(), reversed.end());
	string formated = s + "#" + reversed;
	auto next = makeNext(formated);
	string postfix = s.substr(next.back() + 1);
	string prefix = postfix;
	reverse(prefix.begin(), prefix.end());
	return prefix + s;
}

int main() {
	string arg0 = "abcd";
	cout << shortestPalindrome(arg0);
	cin.get();
}