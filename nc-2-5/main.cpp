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

int N, M;

int main() {
	vector<pii> plans;

	int maxPlanTicket = 1;

	int single;
	scanf("%d%d%d", &N, &M, &single);
	plans.push_back(mp(1, single));
	while (M--) {
		int val, cnt;
		scanf("%d%d", &val, &cnt);
		plans.push_back(mp(cnt, val));
		maxPlanTicket = max(maxPlanTicket, cnt);
	}

	sort(plans.begin(), plans.end());

	vector<int> costOfTicket(1, 0);
	int ret = INT_MAX;
	for (int i = 1; i <= N + 1 || i <= maxPlanTicket + N + 1; ++i) {
		int minCost = INT_MAX;

		for (int j = 0; j < plans.size() && plans[j].first <= i; ++j) {
			int cost = plans[j].second;
			int ticket = plans[j].first;
			minCost = min(minCost, cost + costOfTicket[i - ticket]);
		}

		costOfTicket.push_back(minCost);
		if (i >= N + 1) {
			ret = min(ret, minCost);
		}
	}

	printf("%d", ret);
}