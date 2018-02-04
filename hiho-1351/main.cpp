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

int N, M;

int main() {
	scanf("%d", &N);
	int n = N;

	map<string, int> prodCnts;
	while (n--) {
		scanf("%d", &M);

		set<string> lines;
		while (M--) {
			string id, date, price;
			cin >> id >> date >> price;
			lines.insert(id + price);
		}

		for (auto line : lines) {
			prodCnts[line]++;
		}
	}

	for (auto prodCnt : prodCnts) {
		if (prodCnt.second == N) {
			cout << prodCnt.first.substr(0, 9) << endl;
		}
	}

	return 0;
}