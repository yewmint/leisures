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
#include <stdio.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int T, target, step;
int IDX[] = { 0, 2, 6, 8 };

int serialize(vector<int> & nums) {
	int ret = 0;
	int base = 1;
	for (int i = 8; i >= 0; --i) {
		ret += base * nums[i];
		base *= 10;
	}
	return ret;
}

void rotate(vector<int> & nums, int sub, int move) {
	int begin = sub + sub / 2;

	while (move--) {
		int tmp = nums[begin];
		nums[begin] = nums[begin + 3];
		nums[begin + 3] = nums[begin + 4];
		nums[begin + 4] = nums[begin + 1];
		nums[begin + 1] = tmp;
	}
}

int onlyBegin(vector<int> & a, vector<int> & b) {
	bool top = a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
	bool bottom = a[6] == b[6] && a[7] == b[7] && a[8] == b[8];
	bool left = a[0] == b[0] && a[3] == b[3] && a[6] == b[6];
	bool right = a[2] == b[2] && a[5] == b[5] && a[8] == b[8];

	if (top && left) {
		return 3;
	}
	else if (top && right) {
		return 2;
	}
	else if (bottom && left) {
		return 1;
	}
	else if (bottom && right) {
		return 0;
	}

	return -1;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		vector<int> N(9);
		vector<int> M(9);

		map<int, int> a;
		map<int, int> b;

		for (int i = 0; i < 9; ++i) {
			scanf("%d", &N[i]);
			a[N[i]]++;
		}
		for (int i = 0; i < 9; ++i) {
			scanf("%d", &M[i]);
			b[M[i]]++;
		}

		if (a != b) {
			cout << -1 << endl;
			continue;
		}

		target = serialize(M);
		int curSerial = serialize(N);
		if (curSerial == target) {
			cout << 0 << endl;
			continue;
		}

		unordered_set<int> states({ curSerial });
		vector<vector<int>> curMats({ N });
		vector<vector<int>> nextMats;
		step = 0;
		bool found = false;

		while (true) {
			step++;

			for (auto mat : curMats) {
				int onBeg = onlyBegin(M, mat);
				for (int move = 1; move <= 3 && !found; ++move) {
					if (onBeg != -1) {
						vector<int> tmp(mat);
						rotate(tmp, onBeg, move);
						int serial = serialize(tmp);

						if (serial == target) {
							found = true;
							break;
						}

						if (!states.count(serial)) {
							nextMats.push_back(tmp);
							states.insert(serial);
						}

					}
					else {
						for (int begin = 0; begin < 4 && !found; ++begin) {
							vector<int> tmp(mat);
							rotate(tmp, begin, move);
							int serial = serialize(tmp);

							if (serial == target) {
								found = true;
								break;
							}

							if (!states.count(serial)) {
								nextMats.push_back(tmp);
								states.insert(serial);
							}
						}
					}
				}

				if (found) {
					break;
				}
			}

			if (found) {
				break;
			}

			curMats.swap(nextMats);
		}

		if (found) {
			cout << step << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}