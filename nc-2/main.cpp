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

int T, N;
char road[1006];

int traverse(vector<int> & weights, int idx, int remain, int size) {
	if (idx >= weights.size()) {
		return 1;
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &N, road);

		int ret = 0;
		for (int i = 0; i < N;) {
			if (road[i] == '.') {
				ret++;
				road[i] = road[i + 1] = road[i + 2] = 'X';
				i += 3;
			}
			else {
				++i;
			}
		}

		printf("%d\n", ret);
	}
}