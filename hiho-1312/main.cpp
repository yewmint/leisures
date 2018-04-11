#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>
#include <stdio.h>

#pragma warning(disable:4996)

#define mp make_pair
#define mt make_tuple
typedef long long ll;
using namespace std;

int factorial(int x) {
	int ret = 1;
	for (int i = 2; i <= x; ++i) {
		ret *= i;
	}
	return ret;
}

int cantor(vector<int> & nums) {
	int len = nums.size();
	int x = 0;
	for (int i = 0; i < len; ++i) {
		int tp = 0;
		for (int j = i + 1; j < len; ++j) {
			if (nums[j] < nums[i]) {
				tp++;
			}
		}
		x += tp * factorial(len - i - 1);
	}
	return x;
}

vector<int> uncantor(int len, int order) {
	vector<int> a(len);
	vector<int> nums(len);
	vector<bool> used(len);

	for (int i = 0; i < len; ++i) {
		int fact = factorial(len - i - 1);
		a[i] = order / fact;
		order = order % fact;
		int cnt = 0;

		for (int j = 0; j < len; ++j) {
			if (!used[j]) {
				cnt++;
				if (cnt == a[i] + 1) {
					nums[i] = j;
					used[j] = true;
					break;
				}
			}
		}
	}

	return nums;
}

int evaluate(int init, int target) {
	int ret = 0;

	vector<int> && rawInit = uncantor(9, init);
	vector<int> && rawTarget = uncantor(9, target);

	for (int i = 0; i < rawInit.size(); ++i) {
		int num = rawInit[i];
		if (num == 0) {
			continue;
		}

		int initRow = i / 3;
		int initCol = i % 3;

		auto it = find(rawTarget.begin(), rawTarget.end(), num);
		int targetRow = (it - rawTarget.begin()) / 3;
		int targetCol = (it - rawTarget.begin()) % 3;

		ret += abs(initRow - targetRow) + abs(initCol - targetCol);
	}

	return ret;
}

struct Point {
	int id, f, g, h;

	Point(int id, int f, int g, int h) : id(id), f(f), g(g), h(h) {};

	bool operator<(const Point & another) const {
		return f > another.f || f == another.f && g > another.g;
	}
};

int main() {
	vector<int> rawTarget = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
	int target = cantor(rawTarget);

	int N;
	scanf("%d", &N);
	while (N--) {
		vector<int> rawInit(9);
		for (int i = 0; i < 9; ++i) {
			scanf("%d", &rawInit[i]);
		}
		int init = cantor(rawInit);

		priority_queue<Point> openList;
		set<int> closeList;
		map<int, bool> visited;

		int initEval = evaluate(init, target);
		openList.push(Point(init, initEval, 0, initEval));

		bool found = false;
		while (!openList.empty()) {
			auto pt = openList.top();

			closeList.insert(pt.id);
			openList.pop();

			if (pt.id == target) {
				printf("%d\n", pt.g);
				found = true;
				break;
			}

			vector<int> && rawNums = uncantor(9, pt.id);
			auto itZero = find(rawNums.begin(), rawNums.end(), 0);
			int rowZero = (itZero - rawNums.begin()) / 3;
			int colZero = (itZero - rawNums.begin()) % 3;

			//printf("%d, %d, %d, %d\n", id, step, real, eval);
			//for (int r = 0; r < 3; ++r) {
			//	for (int c = 0; c < 3; ++c) {
			//		printf("%d ", rawNums[3 * r + c]);
			//	}
			//	printf("\n");
			//}
			//printf("\n");

			vector<vector<int>::iterator> swappables;
			if (rowZero > 0) swappables.push_back(itZero - 3);
			if (rowZero < 2) swappables.push_back(itZero + 3);
			if (colZero > 0) swappables.push_back(itZero - 1);
			if (colZero < 2) swappables.push_back(itZero + 1);

			for (auto swappable : swappables) {
				swap(*itZero, *swappable);
				int newId = cantor(rawNums);

				if (closeList.count(newId) > 0) {
					swap(*itZero, *swappable);
					continue;
				}
				else {
					int ev = evaluate(newId, target);
					openList.push(Point(newId, pt.g + 1 + ev, pt.g + 1, ev));
				}

				swap(*itZero, *swappable);
			}
		}

		if (!found) {
			printf("No Solution!\n");
		}
	}
}