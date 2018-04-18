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

int maxEval(set<int> & nums, int P, int Q, int K) {
	int ret = *(--nums.end());
	nums.erase(--nums.end());

	while (nums.size()) {
		if (P > 0) {
			ret += *(--nums.end());
			nums.erase(--nums.end());
			--P;
		}
		else if (K > 0 && Q > 0){
			P = Q - 1;
			Q = 1;
			--K;
		}
		else {
			ret -= *(--nums.end());
			nums.erase(--nums.end());
		}
	}

	return ret;
}

int main() {
	int N, P, Q, K;
	int A[106];
	scanf("%d%d%d%d", &N, &P, &Q, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	sort(A, A + N);

	int ret = 0;
	if (K == 0) {
		for (int i = 0; i < N; ++i) {
			if (i < Q) {
				ret -= A[i];
			}
			else {
				ret += A[i];
			}
		}
	}
	else {
		if (Q > 0) {
			ret = -A[0];
		}
		else {
			ret = A[0];
		}

		for (int i = 1; i < N; ++i) {
			ret += A[i];
		}
	}

	printf("%d\n", ret);
}