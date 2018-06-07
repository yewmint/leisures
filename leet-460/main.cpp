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
typedef pair<int, int> pii;
typedef long long ll;

class LFUCache {
private:
	int size;
	int capacity;

	struct Row {
		int frequency = 0;
		list<pii> vals;
		Row(int frequency) : frequency(frequency) {};
	};

	list<Row> rows;
	unordered_map<int, list<pii>::iterator> valDict;
	unordered_map<int, list<Row>::iterator> rowDict;

private:
	void renew(int key, int val) {
		auto valNode = valDict[key];
		auto rowNode = rowDict[key];

		int curFreq = rowNode->frequency;
		int curVal = valNode->second;

		auto nextRowNode = rowNode;
		nextRowNode++;
		if (nextRowNode == rows.end() || nextRowNode->frequency != curFreq + 1) {
			nextRowNode = rows.insert(nextRowNode, Row(curFreq + 1));
		}

		rowNode->vals.erase(valNode);
		if (rowNode->vals.size() == 0) {
			rows.erase(rowNode);
		}

		nextRowNode->vals.push_back(mp(key, val));
		valDict[key] = --(nextRowNode->vals.end());
		rowDict[key] = nextRowNode;
	}

public:
	LFUCache(int capacity) : capacity(capacity), size(0) {}

	int get(int key) {
		if (valDict.count(key) == 0) {
			return -1;
		}

		int val = valDict[key]->second;
		this->renew(key, val);

		return val;
	}

	void put(int key, int value) {
		if (capacity == 0) {
			return;
		}

		if (valDict.count(key) == 1) {
			this->renew(key, value);
			return;
		}

		if (size == capacity) {
			auto & firstVals = rows.begin()->vals;
			auto keyVal = firstVals.front();
			firstVals.erase(firstVals.begin());

			valDict.erase(keyVal.first);
			rowDict.erase(keyVal.first);

			if (firstVals.empty()) {
				rows.erase(rows.begin());
			}

			size--;
		}

		if (rows.empty() || rows.begin()->frequency != 1) {
			rows.push_front(Row(1));
		}

		rows.begin()->vals.push_back(mp(key, value));
		valDict[key] = --(rows.begin()->vals.end());
		rowDict[key] = rows.begin();

		size++;
	}
};

int main() {
	//LFUCache cache(2);
	//cache.put(1, 1);
	//cache.put(2, 2);
	//cache.get(1);
	//cache.put(3, 3);
	//cache.get(2);
	//cache.get(3);
	//cache.put(4, 4);
	//cache.get(1);
	//cache.get(3);
	//cache.get(4);

	//LFUCache cache(1);
	//cache.put(2, 1);
	//cache.get(2);
	//cache.put(3, 2);
	//cache.get(2);
	//cache.get(3);

	LFUCache cache(2);
	cache.put(3, 1);
	cache.put(2, 1);
	cache.put(2, 2);
	cache.put(4, 4);
	cache.get(2);

	cin.get();
}