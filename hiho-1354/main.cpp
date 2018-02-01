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

#define MAKEWP(weight, row, col) make_pair(weight, make_pair(row, col))

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> B(N + 1, vector<int>(M + 1, -1));
	for (int i = 1; i < N; ++i) {
		int b;
		cin >> b;
		for (int j = 1; j <= M; ++j) {
			B[i][j] = b;
		}
	}

	vector<vector<int>>A(M + 1, vector<int>(N + 1, -1));
	for (int i = 1; i < M; ++i) {
		int a;
		cin >> a;
		for (int j = 1; j <= N; ++j) {
			A[i][j] = a;
		}
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int row, col;
		cin >> row >> col;
		B[row - 1][col] = B[row][col] = -1;
		A[col - 1][row] = A[col][row] = -1;
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int beginRow, beginCol, endRow, endCol;
		cin >> beginRow >> beginCol >> endRow >> endCol;

		set<pair<int, pair<int, int>>> weightPos;
		weightPos.insert(MAKEWP(0, beginRow, beginCol));
		vector<vector<int>> distance(N + 1, vector<int>(M + 1, INT_MAX));
		distance[beginRow][beginCol] = 0;

		bool canReach = false;
		while (!weightPos.empty()) {
			auto curWP = weightPos.begin();
			int curWeight = curWP->first;
			int curRow = curWP->second.first;
			int curCol = curWP->second.second;

			if (curRow == endRow && curCol == endCol) {
				cout << curWeight << endl;
				canReach = true;
				break;
			}

			weightPos.erase(weightPos.begin());

			if (B[curRow][curCol] >= 0) {
				int newWeight = curWeight + B[curRow][curCol];
				if (distance[curRow + 1][curCol] > newWeight) {
					weightPos.insert(MAKEWP(newWeight, curRow + 1, curCol));
					distance[curRow + 1][curCol] = newWeight;
				}
			}

			if (B[curRow - 1][curCol] >= 0) {
				int newWeight = curWeight + B[curRow - 1][curCol];
				if (distance[curRow - 1][curCol] > newWeight) {
					weightPos.insert(MAKEWP(newWeight, curRow - 1, curCol));
					distance[curRow - 1][curCol] = newWeight;
				}
			}

			if (A[curCol][curRow] > 0) {
				int newWeight = curWeight + A[curCol][curRow];
				if (distance[curRow][curCol + 1] > newWeight) {
					weightPos.insert(MAKEWP(newWeight, curRow, curCol + 1));
					distance[curRow][curCol + 1] = newWeight;
				}
			}

			if (A[curCol - 1][curRow] > 0) {
				int newWeight = curWeight + A[curCol - 1][curRow];
				if (distance[curRow][curCol - 1] > newWeight) {
					weightPos.insert(MAKEWP(newWeight, curRow, curCol - 1));
					distance[curRow][curCol - 1] = newWeight;
				}
			}
		}

		if (!canReach) {
			cout << -1 << endl;
		}
	}
}