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

int N, M, K;
int missles[100006];

bool willDefend(int T) {
	int layer = K;
	int hp = M;

	for (int i = 0; i < N; ++i) {
		hp -= missles[i];

		if (hp <= 0) {
			layer--;
			hp = M;

			if (layer <= 0) {
				break;
			}
		}
		else {
			hp = min(hp + T, M);
		}
	}

	return layer > 0;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &missles[i]);
	}

	int minT = 1;
	int maxT = M;
	while (minT <= maxT) {
		int m = (minT + maxT) / 2;
		if (willDefend(m)) {
			maxT = m - 1;
		}
		else {
			minT = m + 1;
		}
	}

	if (minT > M) {
		cout << -1;
	}
	else {
		cout << minT;
	}

	return 0;
}