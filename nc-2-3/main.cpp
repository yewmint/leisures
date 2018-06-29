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
typedef pair<int, int> pii;

int main() {
	vector<int> pile(14, 4);

	int sumA, sumB;
	int a, b, c;
	
	scanf("%d%d%d", &a, &b, &c);
	sumA = a + b + c;

	pile[a]--;
	pile[b]--;
	pile[c]--;

	scanf("%d%d%d", &a, &b, &c);
	sumB = a + b + c;

	pile[a]--;
	pile[b]--;
	pile[c]--;

	int requisite = sumB - sumA + 1;
	
	double ret = 0;
	for (int i = 1; i <= 13; ++i) {
		if (pile[i] == 0 || i + requisite > 13) continue;

		int sizeB;
		if (i + requisite >= 1) {
			pile[i]--;
			sizeB = accumulate(pile.begin() + i + requisite, pile.end(), 0);
			pile[i]++;
		}
		else {
			sizeB = 45;
		}

		double posA = static_cast<double>(pile[i]) / 46.0;
		double posB = static_cast<double>(sizeB) / 45.0;

		ret += posA * posB;
	}

	printf("%.4lf", ret);
}