#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

char str[10006];

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> numCnt(10, 0);
	scanf("%s", str);
	for (int i = 0; i < N; ++i){
		numCnt[str[i] - '0']++;
	}

	int minCost = INT_MAX;
	int minNum = -1;
	for (int num = 0; num < 10; ++num){
		if (numCnt[num] == 0) continue;

		int totalCost = 0;
		int remain = K - numCnt[num];

		for (int cost = 1; remain > 0 && cost <= 9; ++cost){
			int signs[] = { 1, -1 };
			for (int i = 0; remain > 0 && i < 2; ++i){
				int tnum = num + signs[i] * cost;
				if (tnum < 0 || tnum > 9 || numCnt[tnum] == 0) continue;

				totalCost += cost * min(numCnt[tnum], remain);
				remain -= min(numCnt[tnum], remain);
			}
		}

		if (totalCost < minCost) {
			minCost = totalCost;
			minNum = num;
		}
	}

	printf("%d\n", minCost);

	multiset<vector<int>> numVal;
	for (int i = 0; i < N; ++i){
		int num = str[i] - '0';
		if (num == minNum) continue;
		numVal.insert(vector<int>({abs(num - minNum), (minNum - num) * (N - i), -i}));

		if (numVal.size() > K - numCnt[minNum]){
			numVal.erase(prev(numVal.end()));
		}
	}

	for (auto p : numVal){
		str[-p[2]] = '0' + minNum;
	}

	printf("%s", str);
}