#include <bits/stdc++.h>

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

vector<int> smallestRange(vector<vector<int>>& nums) {
	vector<pair<int, int>> sorted;
	for (int row = 0; row < nums.size(); ++row){
		for (int col = 0; col < nums[0].size(); ++col){
			sorted.push_back(mp(nums[row][col], row));
		}
	}

	sort(sorted.begin(), sorted.end());

	auto minRange = mp(0, INT_MAX);
	int remainRow = nums.size();
	vector<int> selectCount(nums.size(), 0);
	int left = -1, right = -1;

	while (remainRow > 0 && right >= nums.size() - 1){
		while (right < nums.size() - 1 && remainRow > 0){
			right++;
			int num = sorted[right].first;
			int row = sorted[right].second;

			if (selectCount[row] == 0){
				remainRow--;
			}
			selectCount[row]++;
		}

		while (left <= right && remainRow == 0){
			left++;
			int num = sorted[left].first;
			int row = sorted[left].second;

			selectCount[row]--;
			if (selectCount[row] == 0){
				remainRow++;
			}
		}

		if (minRange.second - minRange.first > right - left + 1){
			minRange = mp(left - 1, right);
		}
	}

	return vector<int>({ minRange.first, minRange.second });
}

int main() {
	vector<vector<int>> arg0 = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
	auto ans = smallestRange(arg0);
	for (int num : ans){
		cout << num << endl;
	}

	cout << "finished" << endl;
	cin.get();
}