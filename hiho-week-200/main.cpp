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

int N;
int cnt[2];

int main() {
	scanf("%d", &N);
	while (N--) {
		int num;
		scanf("%d", &num);
		cnt[num % 2]++;
	}
	printf("%d", abs(cnt[0] - cnt[1]));
}