#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>
#include <stdio.h>

#pragma warning(disable:4996)

#define mp make_pair
#define mt make_tuple
typedef long long ll;
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<int>> edges(N + 1);
	vector<int> indegree(N + 1);
	vector<int> votes(N + 1);
	vector<bool> isStable(N + 1);

	for (int i = 1; i <= N; ++i) {
		int num;
		scanf("%d", &num);
		indegree[i] = num;

		for (int j = 0; j < num; ++j) {
			int mentor;
			scanf("%d", &mentor);

			edges[mentor].push_back(i);
		}
	}

	queue<int> q;
	for (int dest : edges[0]) {
		isStable[dest] = true;
		indegree[dest]--;
		if (indegree[dest] == 0) {
			q.push(dest);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (votes[node] >= 2) {
			isStable[node] = true;
		}

		for (int dest : edges[node]) {
			indegree[dest]--;
			if (indegree[dest] == 0) {
				q.push(dest);
			}

			if (isStable[node]) {
				votes[dest]++;
			}
		}
	}

	int ret = 0;
	for (bool stable : isStable) {
		ret += stable ? 1 : 0;
	}

	cout << ret;
}