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
#include <stdio.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

set<int> totals;

int main() {
	int N, X;
	scanf("%d%d", &N, &X);

	for (int i = 0; i < N; ++i) {
		int cost;
		scanf("%d", &cost);

		totals.insert(0);
		set<int> oldTotals(totals);
		for (int total : oldTotals) {
			totals.insert(total + cost);
		}
	}

	auto minIt = totals.lower_bound(X);
	if (minIt == totals.end()) {
		cout << -1;
	}
	else {
		cout << *minIt;
	}

	return 0;
}