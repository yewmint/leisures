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

int parent[1006][1006][2] = { 0 };
int ranker[1006][1006] = { 0 };

int dirs[5] = { -1, 0, 1, 0, -1 };

int regionNum = 0;

void root(int row, int col, int &rootRow, int &rootCol) {
	while (parent[row][col][0] != row || parent[row][col][1] != col) {
		int *pos = parent[row][col];
		row = pos[0];
		col = pos[1];
	}

	rootRow = row;
	rootCol = col;
}

void mergeUnion(int arow, int acol, int brow, int bcol) {
	int rarow, racol;
	root(arow, acol, rarow, racol);

	int rbrow, rbcol;
	root(brow, bcol, rbrow, rbcol);

	if (rarow == rbrow && racol == rbcol) {
		return;
	}

	regionNum--;

	if (ranker[rarow][racol] > ranker[rbrow][rbcol]) {
		parent[rbrow][rbcol][0] = rarow;
		parent[rbrow][rbcol][1] = racol;
		ranker[rarow][racol] += ranker[rbrow][rbcol];
	}
	else {
		parent[rarow][racol][0] = rbrow;
		parent[rarow][racol][1] = rbcol;
		ranker[rbrow][rbcol] += ranker[rarow][racol];
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int row, col;
		scanf("%d %d", &row, &col);
		++row;
		++col;

		ranker[row][col] = 1;
		parent[row][col][0] = row;
		parent[row][col][1] = col;
		regionNum++;

		bool isParented = false;
		for (int i = 0; i < 4; ++i) {
			int curRow = row + dirs[i];
			int curCol = col + dirs[i + 1];

			if (curRow <= 0 || curRow > 1000 || curCol <= 0 || curCol > 1000) {
				continue;
			}

			if (ranker[curRow][curCol] > 0) {
				mergeUnion(row, col, curRow, curCol);
			}
		}

		printf("%d\n", regionNum);
	}

	return 0;
}