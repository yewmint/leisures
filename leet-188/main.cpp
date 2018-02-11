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

struct VP {
	int valley, peak;
	VP(int valley, int peak) : valley(valley), peak(peak) {};
};

int maxProfit(int k, vector<int>& prices) {
	priority_queue<int> profits;
	list<VP> candidates;

	bool isDown = true;
	int valley = 0;
	int peak = 0;
	for (int i = 1; i <= prices.size(); ++i) {
		if (isDown) {
			if (i < prices.size() && prices[i - 1] < prices[i]) {
				valley = prices[i - 1];
				isDown = false;
			}
		}
		else if (i == prices.size() || prices[i - 1] > prices[i]) {
			peak = prices[i - 1];
			isDown = true;

			auto it = candidates.begin();
			while (it != candidates.end()) {
				if (valley <= it->valley) {
					profits.push(it->peak - it->valley);
					candidates.erase(it++);
				}
				else if (peak > it->peak) {
					profits.push(it->peak - valley);
					valley = it->valley;
					candidates.erase(it++);
				}
				else {
					break;
				}
			}

			candidates.push_front(VP(valley, peak));
		}
	}

	for (auto vp : candidates) {
		profits.push(vp.peak - vp.valley);
	}

	int sumProfit = 0;
	for (int i = 0; i < k && !profits.empty(); ++i) {
		sumProfit += profits.top();
		profits.pop();
	}

	return sumProfit;
}

int main() {
	vector<int> arg0 = { 1, 4, 2, 3, 2, 5 };
	cout << maxProfit(1, arg0) << endl;
	cout << maxProfit(2, arg0) << endl;
	cout << maxProfit(3, arg0) << endl;
	cin.get();
}