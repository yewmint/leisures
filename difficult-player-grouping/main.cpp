#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		
		priority_queue<int> heroNums;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >>  num;
			heroNums.push(num);
		}

		int teamNum = 0;
		while (true) {
			int tmp[3];

			bool canGroup = true;
			for (int i = 0; i < 3; ++i) {
				if (heroNums.top() > 0) {
					tmp[i] = heroNums.top() - 1;
					heroNums.pop();
				}
				else {
					canGroup = false;
					break;
				}
			}

			if (canGroup) {
				teamNum++;
				for (int i = 0; i < 3; ++i) {
					heroNums.push(tmp[i]);
				}
			}
			else {
				break;
			}
		}

		cout << teamNum / 2 << endl;
	}
}