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

int findMin(vector<int>& nums) {
	vector<int> uniques;
	uniques.push_back(nums.front());

	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] != nums[i - 1] && nums[i] != nums[0]) {
			uniques.push_back(nums[i]);
		}
	}

	int left = 0;
	int right = uniques.size() - 1;

	while (left < right) {
		if (uniques[right] >= uniques[left]) {
			break;
		}

		int mid = (left + right) / 2;
		if (uniques[left] <= uniques[mid]) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return uniques[left];
}

int main() {
	vector<int> arg0 = { 3, 3, 4, 4, 0, 0, 1, 1, 2, 2, 3 };
	//vector<int> arg0 = { 5, 1, 3 };
	//vector<int> arg0 = { 1, 3 };
	cout << findMin(arg0) << endl;

	cin.get();
}