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

ll N;

ll powll(ll a, ll b) {
	ll result = 1;
	for (int i = 0; i < b; ++i) {
		result *= a;
	}
	return result;
}

ll digitCnt(int k) {
	if (k == 1) {
		return 10;
	}
	else {
		return 9 * powll(10, k - 1) * k;
	}
}

int main() {
	scanf("%lld", &N);

	int k = 1;
	while (N >= digitCnt(k)) {
		N -= digitCnt(k++);
	}

	ll num = N / k + powll(10, k - 1);
	if (k == 1) num--;
	ll digitIdx = N % k;

	ll digit = num / powll(10, k - digitIdx - 1);
	digit %= 10;

	printf("%lld", digit);

	return 0;
}