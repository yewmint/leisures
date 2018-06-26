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

using namespace std;
#define mp make_pair
typedef long long ll;

int N, M;
ll BIT2[1006][1006];

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int y, int val) {
	for (int i = x; i <= N; i += lowbit(i)) {
		for (int j = y; j <= N; j += lowbit(j)) {
			BIT2[i][j] += val;
		}
	}
}

ll sum(int x, int y) {
	ll ret = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		for (int j = y; j > 0; j -= lowbit(j)) {
			ret += BIT2[i][j];
		}
	}
	return ret;
}

int main() {
	int n, m;
	N = 1000;
	M = 1000;

	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y, 1);
	}

	scanf("%d", &m);
	while (m--) {
		int lbx, lby, rtx, rty;
		scanf("%d%d%d%d", &lbx, &lby, &rtx, &rty);
		printf("%lld\n", sum(rtx, rty) - sum(rtx, lby - 1) - sum(lbx - 1, rty) + sum(lbx - 1, lby - 1));
	}
}