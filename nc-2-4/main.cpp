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
typedef pair<int, int> pii;

int N;

int main() {
	vector<pii> shows;

	scanf("%d", &N);
	while (N--) {
		int a, b;
		scanf("%d%d", &a, &b);
		shows.push_back(mp(a + b, a));
	}

	sort(shows.begin(), shows.end());

	int curTime = 0;
	int showTimes = 0;
	for (auto show : shows) {
		if (show.second >= curTime) {
			curTime = show.first;
			showTimes++;
		}
	}

	printf("%d", showTimes);
}