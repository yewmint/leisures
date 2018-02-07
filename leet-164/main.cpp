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

struct Num {
	int val;
	int remain;
	Num(int val) : val(val), remain(val) {};
};

int maximumGap(vector<int>& nums) {
	list<Num> ns;
	for (auto num : nums) {
		ns.push_back(num);
	}

	for (int i = 0; i < 31; ++i) {
		list<Num> buckets[2];
		for (auto & num : ns) {
			int idx = num.remain & 1;
			num.remain >>= 1;
			buckets[idx].push_back(num);
		}

		ns = list<Num>();
		ns.insert(ns.end(), buckets[1].begin(), buckets[1].end());
		ns.insert(ns.end(), buckets[0].begin(), buckets[0].end());
	}

	int maxGap = 0;
	auto itp = ns.begin();
	auto it = ++ns.begin();
	for (; it != ns.end(); ++it, ++itp) {
		maxGap = max(maxGap, itp->val - it->val);
	}

	return maxGap;
}

int main() {
	vector<int> arg0 = { 3, 3, 4, 6, 0, 0, 1, 1, 2, 2, 3 };
	//vector<int> arg0 = { 5, 1, 3 };
	//vector<int> arg0 = { 1, 3 };
	cout << maximumGap(arg0) << endl;

	cin.get();
}