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

int region[1006][1006] = { 0 };
int parent[1006][1006][2] = { 0 };

int dirs[5] = { -1, 0, 1, 0, -1 };

void root(int row, int col, int &rootRow, int &rootCol) {
	while (parent[row][col][0] != 0 || parent[row][col][1] != 0) {
		int *pos = parent[row][col];
		row = pos[0];
		col = pos[1];
	}

	rootRow = row;
	rootCol = col;
}

int main() {
	int N;
	scanf("%d", &N);

	int regionIdx = 0;
	int regionNum = 0;
	for (int i = 0; i < N; ++i) {
		int row, col;
		scanf("%d %d", &row, &col);
		++row;
		++col;

		bool isParented = false;
		for (int i = 0; i < 4; ++i) {
			int curRow = row + dirs[i];
			int curCol = col + dirs[i + 1];

			if (curRow <= 0 || curRow > 1000 || curCol <= 0 || curCol > 1000) {
				continue;
			}

			int rootRow, rootCol;
			root(curRow, curCol, rootRow, rootCol);
			int reg = region[rootRow][rootCol];

			if (reg > 0) {
				if (isParented) {
					int myRootRow, myRootCol;
					root(row, col, myRootRow, myRootCol);

					parent[rootRow][rootCol][0] = myRootRow;
					parent[rootRow][rootCol][1] = myRootCol;
					regionNum--;
				}
				else {
					parent[row][col][0] = rootRow;
					parent[row][col][1] = rootCol;
					isParented = true;
				}
			}
		}

		if (!isParented) {
			region[row][col] = ++regionIdx;
			regionNum++;
		}

		printf("%d\n", regionNum);
	}

	return 0;
}