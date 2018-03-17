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
#include "HeapList.h"

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int N, M, L;
int A[1006];

#define IDX(i) ((i + N) % N)

int fix(HeapList<int> & list, int m) {
	if (m == 0) {
		return list.smallest();
	}

	auto curIt = list.bottom();
	for (int i = 0; i < L; ++i) {
		list.erase(curIt--);
	}


}

int main() {
	scanf("%d%d%d", &N, &M, &L);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	vector<int> nums(A, A + N);
	HeapList<int> list(nums);

	return fix(list, M);
}