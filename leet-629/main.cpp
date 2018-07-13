#include <bits/stdc++.h>

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int counts[33][2];

int findIntegers(int num) {
	counts[1][0] = counts[1][1] = 1;
	for (int i = 2; i <= 32; ++i){
		counts[i][0] = counts[i - 1][0] + counts[i - 1][1];
		counts[i][1] = counts[i - 1][0];
	}

	int maxBit = 0, tmpNum = num;
	while (tmpNum > 0) {
		maxBit++;
		tmpNum >>= 1;
	}

	int ret = 0;
	bool isConsecutive = false;
	int last = -1;
	for (int bit = maxBit - 1; bit >= 0; --bit){
		if ((num >> bit) & 0x1 == 1){
			ret += counts[bit + 1][0];

			if (last == 1){
				isConsecutive = true;
				break;
			}
		}

		last = (num >> bit) & 0x1;
	}

	if (!isConsecutive){
		ret++;
	}

	return ret;
}

int main() {
	cout << findIntegers(5) << endl;

	cout << "finished" << endl;
	cin.get();
}