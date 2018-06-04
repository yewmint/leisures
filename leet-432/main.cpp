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

class AllOne {
private:
	struct Row {
		int num;
		list<string> keys;
		Row(int num) : num(num) {};
	};

private: 
	list<Row> rows;
	unordered_map<string, pair<list<string>::iterator, list<Row>::iterator>> dict;

private:
	void newKey(string key) {
		if (rows.empty() || rows.begin()->num != 1) {
			rows.push_front(Row(1));
		}

		rows.begin()->keys.push_front(key);
		dict[key] = mp(rows.begin()->keys.begin(), rows.begin());
	}

	void modify(string key, bool isInc) {
		auto keyNode = dict[key].first;
		auto rowNode = dict[key].second;
		int num = rowNode->num;

		list<Row>::iterator nextRow = rowNode;
		if (isInc) {
			nextRow++;
			if (nextRow == rows.end() || nextRow->num != num + 1) {
				nextRow = rows.insert(nextRow, Row(num + 1));
			}
		}
		else {
			if (nextRow == rows.begin()) {
				nextRow = rows.insert(nextRow, Row(num - 1));
			}
			else if ((--nextRow)->num != num - 1) {
				nextRow++;
				nextRow = rows.insert(nextRow, Row(num - 1));
			}
		}

		this->remove(key);

		nextRow->keys.push_front(key);
		dict[key] = mp(nextRow->keys.begin(), nextRow);
	}

	void remove(string key) {
		auto keyNode = dict[key].first;
		auto rowNode = dict[key].second;

		dict.erase(key);
		rowNode->keys.erase(keyNode);
		if (rowNode->keys.size() == 0) {
			rows.erase(rowNode);
		}
	}

public:
	/** Initialize your data structure here. */
	AllOne() {

	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (dict.count(key) == 0) {
			this->newKey(key);
		}
		else {
			this->modify(key, true);
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (dict.count(key) != 0) {
			int num = dict[key].second->num;
			if (num == 1) {
				this->remove(key);
			}
			else {
				this->modify(key, false);
			}
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (rows.size() == 0) {
			return "";
		}
		else {
			return rows.back().keys.front();
		}
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (rows.size() == 0) {
			return "";
		}
		else {
			return rows.front().keys.front();
		}
	}
};

int main() {
	AllOne ao;
	cout << "max: " << ao.getMaxKey() << ", \tmin: " << ao.getMinKey() << endl;
	ao.inc("a");
	cout << "max: " << ao.getMaxKey() << ", \tmin: " << ao.getMinKey() << endl;
	ao.inc("b");
	cout << "max: " << ao.getMaxKey() << ", \tmin: " << ao.getMinKey() << endl;
	ao.inc("a");
	cout << "max: " << ao.getMaxKey() << ", \tmin: " << ao.getMinKey() << endl;
	ao.dec("b");
	cout << "max: " << ao.getMaxKey() << ", \tmin: " << ao.getMinKey() << endl;
	ao.dec("a");
	cout << "max: " << ao.getMaxKey() << ", \tmin: " << ao.getMinKey() << endl;
	ao.dec("a");
	cout << "max: " << ao.getMaxKey() << ", \tmin: " << ao.getMinKey() << endl;

	cin.get();
}