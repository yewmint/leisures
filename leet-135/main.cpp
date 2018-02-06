#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

int candy(vector<int>& ratings) {
	if (ratings.empty()) return 0;

	vector<int> tmp(ratings);
	int cur = 0;
	ratings.front() = cur;
	for (int i = 1; i < tmp.size(); ++i) {
		int rat = tmp[i];
		int prevRat = tmp[i - 1];
		if (rat > prevRat) {
			ratings[i] = ++cur;
		}
		else if (rat < prevRat) {
			ratings[i] = --cur;
		}
		else {
			ratings[i] = cur;
		}
	}

	bool isDesc = true;
	int minRat = ratings.front();
	int cnt = 1;
	vector<int> tops;

	for (int i = 1; i < ratings.size(); ++i) {
		int rat = ratings[i];
		int prevRat = ratings[i - 1];

		if (prevRat == rat) {
			for (int j = i - cnt; j < i; ++j) {
				ratings[j] -= minRat - 1;
			}

			isDesc = true;
			minRat = rat;
			cnt = 1;
		}
		else {
			if (isDesc) {
				cnt++;

				if (rat > prevRat) {
					isDesc = false;
				}
				else {
					minRat = min(minRat, rat);
				}
			}
			else {
				if (rat < prevRat) {
					for (int j = i - cnt; j < i - 1; ++j) {
						ratings[j] -= minRat - 1;
					}
					tops.push_back(i - 1);

					isDesc = true;
					minRat = rat;
					cnt = 1;
				}
				else {
					cnt++;
				}
			}
		}
	}

	for (int j = ratings.size() - cnt; j < ratings.size(); ++j) {
		ratings[j] -= minRat - 1;
	}

	for (int top : tops) {
		ratings[top] = max(ratings[top - 1] + 1, ratings[top + 1] + 1);
	}

	int candyNum = 0;
	for (int rat : ratings) {
		candyNum += rat;
	}

	return candyNum;
}

int main() {
	vector<int> arg0 = { 5,1,1,1,10,2,1,1,1,3 };
	cout << candy(arg0) << endl;
	cin.get();
}