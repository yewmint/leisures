#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>
#include <unordered_set>
#include <stdio.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	vector<string> words;
	unordered_set<string> st;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string word;
		cin >> word;
		words.push_back(word);
		st.insert(word);
	}

	int ret = 0;
	for (auto word : words) {
		ret += st.count(string(word.rbegin(), word.rend()));
	}

	cout << ret / 2;
}