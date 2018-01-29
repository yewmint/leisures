#include <iostream>
#include <string>

using namespace std;

char testWin(char map[3][3]) {
	for (int row = 0; row < 3; ++row) {
		if (map[row][0] != '_' && map[row][0] == map[row][1] && map[row][1] == map[row][2]) {
			return map[row][0];
		}
	}

	for (int col = 0; col < 3; ++col) {
		if (map[0][col] != '_' && map[0][col] == map[1][col] && map[1][col] == map[2][col]) {
			return map[0][col];
		}
	}

	if (map[1][1] != '_' && map[0][0] == map[1][1] && map[1][1] == map[2][2]) {
		return map[1][1];
	}
	
	if (map[1][1] != '_' && map[2][0] == map[1][1] && map[1][1] == map[0][2]) {
		return map[1][1];
	}

	return '_';
}

int main() {
	int S;
	cin >> S;

	while (S--) {
		char map[3][3];
		int xCnt = 0;
		int oCnt = 0;
		char turn = '_';

		int r = 3;
		while (r--) {
			string line;
			cin >> line;
			
			int c = 3;
			while (c--) {
				char cur = line[c];
				map[r][c] = cur;

				if (cur == 'X') {
					xCnt++;
				}
				else if (cur == 'O') {
					oCnt++;
				}
			}
		}

		if (xCnt == oCnt) {
			turn = 'X';
		}
		else if (xCnt == oCnt + 1) {
			turn = 'O';
		}
		else {
			cout << "Invalid" << endl;
			continue;
		}

		char twin = testWin(map);
		if (twin != '_') {
			cout << twin << " win" << endl;
			continue;
		}
		else if (xCnt + oCnt == 9) {
			cout << "Draw" << endl;
			continue;
		}

		bool canWin = false;
		for (int row = 0; row < 3 && !canWin; ++row) {
			for (int col = 0; col < 3 && !canWin; ++col) {
				if (map[row][col] == '_') {
					map[row][col] = turn;
					char win = testWin(map);
					if (win != '_') {
						cout << "Next win" << endl;
						canWin = true;
					}
					map[row][col] = '_';
				}
			}
		}

		if (!canWin) {
			cout << "Next cannot win" << endl;
		}
	}
}