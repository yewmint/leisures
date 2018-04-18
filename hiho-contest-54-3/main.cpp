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

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<pair<int, int>> elems;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int num;
			scanf("%d", &num);
			elems.push_back(mp(num, i));
		}
	}

	sort(elems.begin(), elems.end());

	int diff = INT_MAX;
	unordered_map<int, int> votes({ mp(elems.front().second, 1) });
	int l = 0;
	int r = 0;
	int low = elems.front().first;
	int high = elems.front().first;
	while (r < elems.size() - 1 || votes.size() >= N) {
		if (votes.size() < N) {
			r++;
			high = elems[r].first;
			votes[elems[r].second]++;
		}
		else {
			diff = min(diff, high - low);

			if (l >= r) {
				break;
			}

			if (--votes[elems[l].second] == 0) {
				votes.erase(elems[l].second);
			}
			low = elems[++l].first;
		}
	}

	printf("%d", diff);
}