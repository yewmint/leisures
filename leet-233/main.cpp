#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

#define mp make_pair

int countDigitOne(int n) {
	if (n < 1) {
		return 0;
	}
	else if (n < 10) {
		return 1;
	}

	int figure = 1;
	int num = n;
	while (num >= 10) {
		figure++;
		num /= 10;
	}

	int sum = 1;
	for (int i = 2; i < figure; ++i) {
		sum = sum * 10 + pow(10, i - 1);
	}

	int ans = num * sum;
	ans += num > 1 ? pow(10, figure - 1) : 0;

	ans += countDigitOne(n - num * pow(10, figure - 1));
	ans += num == 1 ? n - num * pow(10, figure - 1) + 1 : 0;

	return ans;
}

int main() {
	cout << countDigitOne(13);
	cin.get();
}