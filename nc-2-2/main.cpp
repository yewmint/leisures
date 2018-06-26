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

int park[1006][1006];
bool inQueue[1006][1006];
int N;

int dirs[] = { 1, 0, -1, 0, 1 };

enum {
	Empty = 0,
	Obstacle = 1,
	Destination = 2
};

int main() {
	scanf("%d%d", &N);

	vector<pii> origins;
	pii dest;
	for (int i = 1; i <= N; ++i) {
		char ch;
		for (int j = 1; j <= N; ++j) {
			scanf("%c", &ch);

			if (ch == '#') {
				park[i][j] = Obstacle;
			}
			else if (ch == '*') {
				dest = mp(i, j);
			}
			else if (ch == '@') {
				origins.push_back(mp(i, j));
			}
		}
		scanf("%c", &ch);
	}

	int shortest = INT_MAX;

	vector<vector<int>> costMap(N + 1, vector<int>(N + 1, INT_MAX));
	queue<pii> spfQueue;

	for (auto origin : origins) {
		costMap[origin.first][origin.second] = 0;
		spfQueue.push(origin);
		inQueue[origin.first][origin.second] = true;
	}

	while (!spfQueue.empty()) {
		pii curPos = spfQueue.front();
		spfQueue.pop();
		inQueue[curPos.first][curPos.second] = false;
		int curCost = costMap[curPos.first][curPos.second];

		for (int i = 0; i < 4; ++i) {
			int x = curPos.first + dirs[i];
			int y = curPos.second + dirs[i + 1];

			if (x >= 1 && x <= N && y >= 1 && y <= N) {
				if (park[x][y] == Empty && costMap[x][y] > curCost + 1) {
					costMap[x][y] = curCost + 1;

					if (!inQueue[x][y]) {
						spfQueue.push(mp(x, y));
						inQueue[x][y] = true;
					}
				}
			}
		}
	}

	printf("%d", costMap[dest.first][dest.second]);
}