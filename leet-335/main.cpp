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

#define mp make_pair
typedef long long ll;

bool isSelfCrossing(vector<int>& x) {
	if (x.size() < 4) {
		return false;
	}

	for (int i = 3; i < x.size(); ++i) {
		if (x[i - 3] >= x[i - 1] && x[i - 2] <= x[i]) {
			return true;
		}

		if (i >= 4 && x[i - 3] == x[i - 1] && x[i - 2] <= x[i - 4] + x[i]) {
			return true;
		}

		if (i >= 5 && x[i - 4] < x[i - 2] && x[i - 4] + x[i] >= x[i - 2] && x[i - 3] >= x[i - 1] && x[i - 5] + x[i - 1] >= x[i - 3]) {
			return true;
		}
	}

	return false;
}

int main() {
	vector<int> arg0 = { 1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1 };
	//vector<int> arg0 = { 1, 1, 2, 1, 1 };
	cout << boolalpha << isSelfCrossing(arg0);

	cin.get();
}