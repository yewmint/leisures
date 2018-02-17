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

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (front.empty()) {
			front.push(num);
		}
		else if (num > front.top()) {
			back.push(num);
		}
		else {
			front.push(num);
		}

		if (front.size() < back.size()) {
			front.push(back.top());
			back.pop();
		}
		else if (front.size() > back.size() + 1) {
			back.push(front.top());
			front.pop();
		}
	}

	double findMedian() {
		if (front.size() == back.size()) {
			return (front.top() + back.top()) / 2.0;
		}
		else {
			return front.top();
		}
	}

	priority_queue<int> front;
	priority_queue<int, vector<int>, greater<int>> back;
};

int main() {
	MedianFinder mf;
	mf.addNum(1);
	mf.addNum(2);
	cout << mf.findMedian() << endl;
	mf.addNum(3);
	cout << mf.findMedian() << endl;
	cin.get();
}