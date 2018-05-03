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
#include <numeric>
#include <stdio.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	set<pair<int, int>> rawRanges;

	int N, Q;
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		int begin, end;
		scanf("%d%d", &begin, &end);
		rawRanges.insert(mp(begin, end));
	}

	set<pair<int, int>> ranges;
	while (rawRanges.size() > 0) {
		int begin = rawRanges.begin()->first;
		int end = rawRanges.begin()->second;
		rawRanges.erase(rawRanges.begin());

		while (rawRanges.size() > 0 && rawRanges.begin()->first <= end) {
			end = max(end, rawRanges.begin()->second);
			rawRanges.erase(rawRanges.begin());
		}

		ranges.insert(mp(begin, end));
	}

	int total = 0;
	map<int, pair<int, int>> spares;
	if (ranges.begin()->first > 1) {
		total += ranges.begin()->first - 1;
		spares[total] = (mp(1, ranges.begin()->first - 1));
	}

	while (ranges.size() >= 2) {
		auto a = ranges.begin();
		auto b = ++ranges.begin();

		if (b->first - a->second > 1) {
			total += b->first - a->second - 1;
			spares[total] = (mp(a->second + 1, b->first - 1));
		}

		ranges.erase(a);
	}

	if (ranges.begin()->second < INT_MAX) {
		total += INT_MAX - ranges.begin()->second;
		spares[total] = (mp(ranges.begin()->second + 1, INT_MAX));
	}

	for (int i = 0; i < Q; ++i) {
		int idx;
		scanf("%d", &idx);
		auto p = spares.lower_bound(idx);

		int innerIdx;
		if (p == spares.begin()) {
			innerIdx = idx;
		}
		else {
			auto prev = --spares.lower_bound(idx);
			innerIdx = idx -= prev->first;
		}

		printf("%d\n", p->second.first + innerIdx - 1);
	}
}