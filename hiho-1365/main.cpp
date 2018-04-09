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

int M, N, W[100006], H[100006];
int Height[100006], Width[100006], BotHeight[100006];
int TailHeight[106][100006], FirstHeight[106][100006];

void traverse(int start, int initWidth) {
	int level = 0, index = start, height = 0;
	while (index < N) {
		++level;
		int levelHeight = 0;
		int width = 0;
		if (level == 1) {
			width = initWidth;
		}

		while (width < M && index < N) {
			int curWidth = W[index];
			int curHeight = H[index];
			if (M - width < curWidth) {
				curWidth = M - width;
				curHeight = ceil(static_cast<double>(curWidth) * H[index] / W[index]);
			}

			width += curWidth;
			levelHeight = max(levelHeight, curHeight);

			if (start == 0 && initWidth == 0) {
				Height[index] = height;
				Width[index] = width;
				BotHeight[index] = levelHeight;
			}

			++index;
		}

		height += levelHeight;
		if (level == 1) {
			FirstHeight[initWidth][start] = height;
		}
	}

	TailHeight[initWidth][start] = height - FirstHeight[initWidth][start];
}

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &W[i], &H[i]);
	}

	for (int j = 0; j < M; ++j) {
		for (int i = 0; i < N; ++i) {
			traverse(i, j);
		}
	}

	int minHeight = numeric_limits<int>::max();
	for (int i = 0; i < N; ++i) {
		int top = i == 0 ? 0 : Height[i - 1];
		int topCentralHeight = i == 0 ? 0 : BotHeight[i - 1];

		int centralWidth = i == 0 ? 0 : Width[i - 1];

		if (centralWidth == M) {
			top += topCentralHeight;
			topCentralHeight = 0;
			centralWidth = 0;
		}

		int bottom = i == N - 1 ? 0 : TailHeight[centralWidth][i + 1];
		int bottomCentralHeight = i == N - 1 ? 0 : FirstHeight[centralWidth][i + 1];

		int centralHeight = max(topCentralHeight, bottomCentralHeight);

		minHeight = min(minHeight, top + bottom + centralHeight);
	}

	cout << minHeight;
}