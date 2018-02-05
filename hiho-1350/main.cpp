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

int N;
bool selected[12];

int main() {
	scanf("%d", &N);

	for (int hour = 0; hour < 24; ++hour) {
		for (int minute = 0; minute < 60; ++minute) {
			int n = 0;
			int h = hour, m = minute;

			while (h > 0) {
				n += h & 1;
				h >>= 1;
			}

			while (m > 0) {
				n += m & 1;
				m >>= 1;
			}

			if (n == N) {
				printf("%02d:%02d\n", hour, minute);
			}
		}
	}

	return 0;
}