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

int main() {
	int P, Q;
	scanf("%d%d", &P, &Q);

	set<int> st;
	int cnt = 0;
	while (cnt < 100) {
		P *= 10;
		int factor = P / Q;
		P %= Q;

		st.insert(factor);
		++cnt;
	}

	for (int num : st) {
		cout << num;
	}
}