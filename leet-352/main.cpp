#include <iostream>
#include <string>
#include <sstream>
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
#include <numeric>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

#define mp make_pair
typedef long long ll;

class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		if (intervals.empty()) {
			intervals[val] = val;
		}

		if (val == 2) {
			int a = 1 + 1;
		}

		auto next = intervals.lower_bound(val);
		if (next != intervals.end() && next->first == val) {
			return;
		}

		if (next != intervals.begin() && (--next)->second >= val) {
			return;
		}

		next = intervals.lower_bound(val);
		if (next != intervals.end()) {
			if (next != intervals.begin()) {
				auto prev = (--next)++;
				if (prev->second == val - 1) {
					if (next->first == val + 1) {
						int begin = prev->first;
						int last = next->second;
						intervals.erase(next->first);
						intervals[begin] = last;
						return;
					}
					else {
						int begin = prev->first;
						intervals[begin] = val;
						return;
					}
				}
				else if (next->first == val + 1) {
					int end = next->second;
					intervals.erase(next->first);
					intervals[val] = end;
					return;
				}
			}
			else if (next->first == val + 1) {
				int end = next->second;
				intervals.erase(next->first);
				intervals[val] = end;
				return;
			}
		}
		else {
			auto prev = (--next)++;
			if (prev->second == val - 1) {
				int begin = prev->first;
				intervals[begin] = val;
				return;
			}
		}

		intervals[val] = val;
	}

	vector<Interval> getIntervals() {
		vector<Interval> ret;
		for (auto pa : intervals) {
			ret.push_back(Interval(pa.first, pa.second));
		}
		return ret;
	}

private:
	map<int, int> intervals;
};

void print(vector<Interval> intervals) {
	for (auto interval : intervals) {
		printf("(%d, %d) ", interval.start, interval.end);
	}
	cout << endl;
}

int main() {
	SummaryRanges ranges;
	ranges.addNum(1);
	print(ranges.getIntervals());
	ranges.addNum(3);
	print(ranges.getIntervals());
	ranges.addNum(7);
	print(ranges.getIntervals());
	ranges.addNum(2);
	print(ranges.getIntervals());
	ranges.addNum(6);
	print(ranges.getIntervals());

	cin.get();
}