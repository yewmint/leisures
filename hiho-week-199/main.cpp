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

int N, B[1006];
int M, A[1006];
int K, X[36], Y[36];
int CXK, CX[66];
int CYK, CY[66];
int SX, SY, EX, EY;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i < N; ++i) {
		scanf("%d", &B[i]);
	}
	for (int i = 1; i < M; ++i) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d%d", &X[i], &Y[i]);
	}

	scanf("%d%d%d%d", &SX, &SY, &EX, &EY);

	set<int> compX(X, X + K);
	compX.insert(SX);
	compX.insert(EX);
	for (int num : compX) {
		if (num + 1 <= N) {
			compX.insert(num + 1);
		}
	}
	if (*compX.begin() - 1 >= 1) {
		compX.insert(*compX.begin() - 1);
	}

	vector<int> cptX(compX.begin(), compX.end());
	CXK = cptX.size() - 1;
	for (int i = 0; i < cptX.size() - 1; ++i) {
		int sumWeight = 0;
		for (int j = cptX[i]; j < cptX[i + 1]; ++j) {
			sumWeight += X[i];
		}
		CX[i + 1] = sumWeight;
	}
}