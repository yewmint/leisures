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

int main() {
	int N;
	scanf("%d", &N);
	unordered_set<string> strs;

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		string line;
		cin >> line;

		for (int i = 0; i < line.size(); ++i) {
			for (int j = i + 1; j < line.size(); ++j) {
				if (line[i] == line[j]) {
					continue;
				}

				swap(line[i], line[j]);
				if (strs.count(line) > 0) {
					ret++;
				}
				swap(line[i], line[j]);
			}
		}

		strs.insert(line);
	}

	printf("%d", ret);
}