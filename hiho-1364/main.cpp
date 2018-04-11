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
#define mt make_tuple
typedef long long ll;
using namespace std;

int N, M;

int main() {
	scanf("%d%d", &N, &M);
	map<int, int> rawPresents;
	for (int i = 0; i < N; ++i) {
		int w, p;
		scanf("%d%d", &w, &p);
		rawPresents[w * 100 + p]++;
	}

	vector<pair<int, int>> presents;
	for (auto preCnt : rawPresents) {
		int w = preCnt.first / 100;
		int p = preCnt.first % 100;
		int cnt = preCnt.second;
		int powNum = 0;

		while (true) {
			int powRet = pow(2, powNum);
			if (cnt <= powRet) {
				break;
			}

			presents.push_back(mp(w * powRet, p * powRet));
			cnt -= powRet;
			powNum += 1;
		}

		presents.push_back(mp(w * cnt, p * cnt));
	}

	int preLen = presents.size();
	vector<int> dpa(M + 1, 0);
	vector<int> dpb(M + 1, 0);

	for (int i = 1; i <= preLen; ++i) {
		int w = presents[i - 1].first;
		int p = presents[i - 1].second;

		for (int j = 1; j <= M; ++j) {
			dpb[j] = max(dpa[j], j >= w ? dpa[j - w] + p : 0);
		}

		dpa.swap(dpb);
		dpb.assign(M + 1, 0);
	}

	printf("%d", dpa[M]);
}