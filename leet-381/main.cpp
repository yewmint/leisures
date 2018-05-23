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
typedef pair<int, int> pii;

class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		nums.push_back(val);
		poses.insert(mp(val, nums.size() - 1));
		return poses.find(val) == poses.end();
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		bool exists = poses.find(val) != poses.end();
		if (exists) {
			auto it = poses.find(val);
			int pos = it->second;

			if (pos != nums.size() - 1) {
				nums[pos] = nums.back();

				auto range = poses.equal_range(nums.back());
				auto backIt = range.second;
				advance(backIt, -1);
				backIt->second = pos;
			}

			nums.pop_back();
			poses.erase(it);

			return true;
		}
		else {
			return false;
		}
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}

public:
	vector<int> nums;
	unordered_multimap<int, int> poses;
};

int main() {
	RandomizedCollection collection;
	collection.insert(1);
	collection.insert(1);
	collection.insert(2);
	cout << collection.getRandom() << endl;
	collection.remove(1);
	cout << collection.getRandom() << endl;

	cin.get();
}