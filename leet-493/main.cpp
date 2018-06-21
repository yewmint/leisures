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

template<typename T1, typename T2>
inline T1 sc(T2 val) { return static_cast<T1>(val); }

template <typename T>
class Fenwick {
public:
	Fenwick(int len = 0) : _data(std::vector<T>(len + 1, 0)) {}

	Fenwick(std::vector<T> & nums) : _data(std::vector<T>(nums.size() + 1, 0)) {
		for (int i = 0; i < nums.size(); ++i) {
			this->add(i, nums[i]);
		}
	}

	void add(int index, T value) {
		if (index < 0) {
			return;
		}

		index++;

		while (index <= this->size()) {
			this->_data[index] += value;
			index += index & (-index);
		}
	}

	T sum(int index) {
		if (index < 0) {
			return 0;
		}

		T sum = 0;
		index++;

		while (index > 0) {
			sum += this->_data[index];
			index -= index & (-index);
		}
		return sum;
	}

	int size() {
		return this->_data.size() - 1;
	}

private:
	std::vector<T> _data;
};

int reversePairs(vector<int>& nums) {
	vector<int> sorted(nums);
	sort(sorted.begin(), sorted.end());

	Fenwick<int> fw(nums.size());
	int count = 0;

	for (int num : nums) {
		int numIdx = lower_bound(sorted.begin(), sorted.end(), num) - sorted.begin();
		int targetIdx = upper_bound(sorted.begin(), sorted.end(), sc<ll>(num) * 2) - sorted.begin();

		count += fw.sum(fw.size() - 1) - fw.sum(targetIdx - 1);
		fw.add(numIdx, 1);
	}

	return count;
}

int main() {
	vector<int> arg0 = { 2,4,3,5,1 };
	cout << reversePairs(arg0) << endl;
	cin.get();
}