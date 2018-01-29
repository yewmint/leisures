#include <iostream>
#include <string>

using namespace std;

struct Pos {
	int row;
	int col;
	Pos(int row = 0, int col = 0) : row(row), col(col) {};
	bool operator==(Pos other) { 
		return row == other.row && col == other.col;
	};
};

int main() {
	int N, M, S;
	cin >> N >> M >> S;

	Pos player;
	Pos box;
	Pos dest;

	char **map = new char*[M + 2];
	for (int i = 0; i < M + 2; ++i) {
		map[i] = new char[N];

		string line;
		if (i != 0 && i != M + 1) {
			cin >> line;
		}

		for (int j = 0; j < N + 2; ++j) {
			if (i == 0 || j == 0 || i == M + 1 || j == N + 1) {
				map[i][j] = 4;
			} 
			else {
				char curTile = line[j - 1];

				if (curTile == '4') {
					map[i][j] = '4';
				}
				else {
					map[i][j] = '0';
				}

				if (curTile == '1') {
					player.row = i;
					player.col = j;
				}
				else if (curTile == '2') {
					dest.row = i;
					dest.col = j;
				}
				else if (curTile == '3') {
					box.row = i;
					box.col = j;
				}
			}
		}
	}

	Pos playerInit = player;
	Pos boxInit = box;

	while (S--) {
		int stepLen;
		string step;
		cin >> stepLen >> step;

		player = playerInit;
		box = boxInit;
		bool willFinish = false;

		for (char curStep : step) {
			int deltRow = 0, deltCol = 0;
			switch (curStep) {
			case 'u':
				deltRow = -1;
				break;
			case 'r':
				deltCol = 1;
				break;
			case 'd':
				deltRow = 1;
				break;
			case 'l':
				deltCol = -1;
				break;
			}

			Pos next(player.row + deltRow, player.col + deltCol);
			char nextTile = map[next.row][next.col];
			if (next == box) {
				Pos boxNext(next.row + deltRow, next.col + deltCol);
				if (boxNext == dest) {
					cout << "YES" << endl;
					willFinish = true;
					break;
				}

				char nextBoxTile = map[boxNext.row][boxNext.col];
				if (nextBoxTile == '0') {
					player = next;
					box = boxNext;
				}
			}
			else if (nextTile == '0') {
				player = next;
			}
		}

		if (!willFinish) {
			cout << "NO" << endl;
		}
	}
}