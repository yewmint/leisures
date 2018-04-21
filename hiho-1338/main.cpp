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

int A[1006];
int profits[1006][1006];
int sums[1006];

int main() {
	int N;
	scanf("%d", &N);

	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		sum += A[i];
		sums[i] = sum;
	}

	for (int i = 1; i <= N; ++i) {
		profits[i][i] = A[i];
	}

	for (int len = 2; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; ++i) {
			int j = i + len - 1;
			int sum = sums[j] - sums[i - 1];
			profits[i][j] = max(sum - profits[i + 1][j], sum - profits[i][j - 1]);
		}
	}

	printf("%d", profits[1][N]);
}