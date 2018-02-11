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

int N, K;
int A[16], B[16];
priority_queue<pair<double, pair<int, int>>> attrs;

double calcStep(int a, int b) {
	double diff = log(a + 1) - log(a);
	return diff / b;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < K; ++i) {
		scanf("%d", &B[i]);
	}

	for (int i = 0; i < K; ++i) {
		double step = calcStep(A[i], B[i]);
		attrs.push(mp(step, mp(A[i], B[i])));
	}

	for (int i = 0; i < N; ++i) {
		auto maxPair = attrs.top();
		attrs.pop();

		maxPair.second.first++;
		maxPair.first = calcStep(maxPair.second.first, maxPair.second.second);

		attrs.push(maxPair);
	}

	double sum = 1;
	for (int i = 0; i < K; ++i) {
		auto ab = attrs.top().second;
		attrs.pop();
		sum *= pow(ab.first, 1.0 / ab.second);
	}

	cout.precision(10);
	cout << sum << endl;
}