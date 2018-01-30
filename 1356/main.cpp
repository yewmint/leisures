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

#define last(container) (--container.end())

using namespace std;

int main() {
	int N;
	cin >> N;
	int n = N;

	map<int, int> numCnt;
	while (N--) {
		int num;
		cin >> num;
		numCnt[num]++;
	}

	set<pair<int, int>> cntNum;
	for (auto &pair : numCnt) {
		cntNum.insert(make_pair(pair.second, pair.first));
	}

	auto maxCnt = last(cntNum)->first;
	if (maxCnt * 2 - 1 > n) {
		cout << -1;
		return 0;
	}
	
	int left = n;
	int prevNum = -1;
	while (!cntNum.empty()) {
		int num;

		if (last(cntNum)->first * 2 - 1 == left) {
			num = last(cntNum)->second;
		}
		else {
			auto minPair = numCnt.begin();

			if (minPair->first == prevNum) {
				minPair++;
			}

			num = minPair->first;
		} 

		cout << num << " ";
		prevNum = num;

		cntNum.erase(make_pair(numCnt[num], num));
		if (--numCnt[num] > 0) {
			cntNum.insert(make_pair(numCnt[num], num));
		}
		else {
			numCnt.erase(num);
		}

		left--;
	}

	cout << endl;
}