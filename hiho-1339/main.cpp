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

double chances[106][606];

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= 6; ++i) {
		chances[1][i] = 1.0 / 6;
	}

	for (int times = 2; times <= N; ++times) {
		for (int sum = times; sum <= times * 6 && sum <= M - (N - times); ++sum) {
			double chance = 0;
			for (int i = 1; i <= 6 && sum - i >= times - 1; ++i) {
				chance += chances[times - 1][sum - i] * (1.0 / 6);
			}
			chances[times][sum] = chance;
		}
	}

	printf("%.2lf", chances[N][M] * 100);
}