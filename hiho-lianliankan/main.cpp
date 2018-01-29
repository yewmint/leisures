#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> Pos;

int visitWay(Pos pos, int deltRow, int deltCol, int tile, vector<Pos> &nextPositions, vector<vector<int>> &map, vector<vector<bool>> &visited) {
	int curTile = -1;
	while (true) {
		pos.first += deltRow;
		pos.second += deltCol;

		if (pos.first < 0 ||
			pos.first >= map.size() ||
			pos.second < 0 ||
			pos.second >= map[0].size()
			) {
			return 0;
		}

		curTile = map[pos.first][pos.second];
		if (curTile != 0) break;


		if (!visited[pos.first][pos.second]) {
			visited[pos.first][pos.second] = true;
			nextPositions.push_back(pos);
		}
	}

	if (map[pos.first][pos.second] == tile) {
		map[pos.first][pos.second] = -1;
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int S;
	cin >> S;

	while (S--) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> map(N, vector<int>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, false));
		for (int row = 0; row < N; ++row) {
			for (int col = 0; col < M; ++col) {
				cin >> map[row][col];
			}
		}

		int X, Y, K;
		cin >> X >> Y >> K;
		int times = K + 1;
		int tile = map[Y - 1][X - 1];
		int tileCnt = 0;

		vector<Pos> positions({ Pos(Y - 1, X - 1) });
		while (times--) {
			vector<Pos> nextPositions;
			for (Pos pos : positions) {
				tileCnt += visitWay(pos, -1, 0, tile, nextPositions, map, visited);
				tileCnt += visitWay(pos, 1, 0, tile, nextPositions, map, visited);
				tileCnt += visitWay(pos, 0, -1, tile, nextPositions, map, visited);
				tileCnt += visitWay(pos, 0, 1, tile, nextPositions, map, visited);
			}
			positions = nextPositions;
		}

		cout << tileCnt << endl;
	}
}