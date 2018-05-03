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

int T, N, tmp;
int M[206];

int main() {
	scanf("%d", &T);
	while (T--) {
		map<int, int> cont;

		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &tmp);
			cont[tmp] = i;
		}

		map<int, int> rev;
		for (auto pair : cont) {
			rev[pair.second] = pair.first;
		}

		for (auto it = rev.rbegin(); it != rev.rend(); ++it) {
			cout << it->second;
			if (it != --rev.rend()) {
				cout << " ";
			}
		}

		cout << endl;
	}
}