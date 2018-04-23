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

int N, M;
ll BIT2[1006][1006];
ll mod = 1000000000ll + 7;

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
	scanf("%d%d", &N, &M);
	while (M--) {
		char query[10];
		scanf("%s", query);

		if (strcmp(query, "Add") == 0) {
			int x, y, val;
			scanf("%d%d%d", &x, &y, &val);
			add(x + 1, y + 1, val);
		}
		else {
			int ax, ay, bx, by;
			scanf("%d%d%d%d", &ax, &ay, &bx, &by);
			bx++; by++;

			ll ret = sum(bx, by) + sum(ax, ay) - sum(bx, ay) - sum(ax, by);
			printf("%ld\n", (ret + mod) % mod);
		}
	}
}