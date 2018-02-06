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

#define mp make_pair

struct Data {
	int key, val;
	Data(int key, int val) : key(key), val(val) {};
};
typedef list<Data>::iterator Lit;

class LRUCache {
public:
	int capacity;
	unordered_map<int, Lit> cache;
	list<Data> q;

	LRUCache(int capacity) : capacity(capacity) {}

	void put(int key, int value) {
		if (cache.count(key) > 0) {
			renewItem(key, value);
		}
		else {
			newItem(key, value);
		}
	}

	int get(int key) {
		if (cache.count(key) > 0) {
			int val = cache[key]->val;
			renewItem(key, val);
			return val;
		}
		else {
			return -1;
		}
	}

	void newItem(int key, int val) {
		if (cache.size() >= capacity) {
			cache.erase(q.back().key);
			q.pop_back();
		}

		q.push_front(Data(key, val));
		cache[key] = q.begin();
	}

	void renewItem(int key, int val) {
		q.erase(cache[key]);
		q.push_front(Data(key, val));
		cache[key] = q.begin();
	}
};

int main() {
	LRUCache cache(3 /* capacity */);

	//cache.put(1, 1);
	//cache.put(2, 2);
	//cout << cache.get(1) << endl;       // returns 1
	//cache.put(3, 3);    // evicts key 2
	//cout << cache.get(2) << endl;       // returns -1 (not found)
	//cache.put(4, 4);    // evicts key 1
	//cout << cache.get(1) << endl;       // returns -1 (not found)
	//cout << cache.get(3) << endl;       // returns 3
	//cout << cache.get(4) << endl;       // returns 4

	cache.put(1, 1);
	cache.put(2, 2);
	cache.put(3, 3);
	cache.put(4, 4);
	cout << cache.get(4) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(2) << endl;
	cout << cache.get(1) << endl;
	cache.put(5, 5);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cout << cache.get(5) << endl;

	cin.get();
}