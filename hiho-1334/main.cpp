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
#include <unordered_map>
#include <numeric>
#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int N;
set<pair<int, vector<bool>>> heap;

int main() {
	cin >> N;

	int maxHeight = 1;
	while (N--) {
		string word;
		cin >> word;

		for (auto levelMark : heap) {
			int level = levelMark.first;
			auto mark = levelMark.second;

			bool overlay = false;
			for (char ch : word) {
				if (mark[ch - 'a']) {
					overlay = true;
					break;
				}
				else {
					mark[ch - 'a'] = true;
				}
			}

			if (!overlay) {
				heap.insert(mp(level + 1, mark));
				maxHeight = max(maxHeight, level + 1);
			}
		}

		vector<bool> mark(26);
		for (char ch : word) {
			mark[ch - 'a'] = true;
		}
		heap.insert(mp(1, mark));
	}

	cout << maxHeight;
}