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

int L, R;

int mod3(int num) {
	int ret = (num / 9) * 6;

	int mod = num % 9;
	ret += (mod / 3) * 2;

	mod = mod % 3;
	ret += mod == 2 ? 1 : 0;

	return ret;
}

int main() {
	scanf("%d%d", &L, &R);

	printf("%d", mod3(R) - mod3(L - 1));
}