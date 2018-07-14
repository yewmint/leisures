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
		for (int col = 0; col < nums[row].size(); ++col){
			sorted.push_back(mp(nums[row][col], row));
		}
	}

	sort(sorted.begin(), sorted.end());

	auto minRange = mp(0, INT_MAX);
	int remainRow = nums.size();
	vector<int> selectCount(nums.size(), 0);
	int left = -1, right = -1;

	bool moved = true;
	while (moved){
		moved = false;

		while (right + 1 < sorted.size() && remainRow > 0){
			moved = true;
			right++;
			int num = sorted[right].first;
			int row = sorted[right].second;

			if (selectCount[row] == 0){
				remainRow--;
			}
			selectCount[row]++;
		}

		// cout << "right to " << right << endl;

		while (left <= right && remainRow <= 0){
			moved = true;
			left++;
			int num = sorted[left].first;
			int row = sorted[left].second;

			selectCount[row]--;
			if (selectCount[row] <= 0){
				remainRow++;
			}
		}

		// cout << "left to " << left << endl;

		if (minRange.second - minRange.first > 
			sorted[right].first - sorted[left].first){
			minRange = mp(sorted[left].first, sorted[right].first);

			// cout << "Updated !" << endl;
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