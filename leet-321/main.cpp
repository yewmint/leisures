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

typedef list<int> NumList;

void dropOne(NumList & list) {
	if (list.empty()) {
		return;
	}

	auto prev = list.begin();
	auto cur = ++list.begin();
	while (cur != list.end()) {
		if (*cur > *prev) {
			break;
		}

		++prev;
		++cur;
	}

	list.erase(prev);
}

void dropN(NumList & list, int k) {
	while (k--) {
		dropOne(list);
	}
}

NumList merge(const NumList & listA, const NumList & listB) {
	NumList ret;

	auto ita = listA.begin();
	auto itb = listB.begin();
	while (ita != listA.end() && itb != listB.end()) {
		auto tita = ita;
		auto titb = itb;

		while (tita != listA.end() && titb != listB.end() && *tita == *titb) {
			++tita;
			++titb;
		}

		bool useA = true;
		if (tita == listA.end() && titb != listB.end()) {
			useA = false;
		}
		else if (tita != listA.end() && titb == listB.end()) {
			useA = true;
		}
		else if (tita != listA.end() && titb != listB.end()) {
			if (*tita > *titb) {
				useA = true;
			}
			else {
				useA = false;
			}
		}

		if (useA) {
			ret.push_back(*ita);
			++ita;
		}
		else {
			ret.push_back(*itb);
			++itb;
		}
	}

	ret.insert(ret.end(), ita, listA.end());
	ret.insert(ret.end(), itb, listB.end());

	return ret;
}

int compare(const NumList & listA, const NumList & listB) {
	auto ita = listA.begin();
	auto itb = listB.begin();
	while (ita != listA.end() && itb != listB.end()) {
		if (*ita > *itb) {
			return 1;
		}
		else if (*ita < *itb) {
			return -1;
		}
		++ita;
		++itb;
	}
	return 0;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	NumList biggest(k, 0);

	for (int lenA = 0; lenA <= k; ++lenA) {
		int lenB = k - lenA;
		if (lenA > nums1.size() || lenB > nums2.size()) {
			continue;
		}

		NumList seqA(nums1.begin(), nums1.end());
		NumList seqB(nums2.begin(), nums2.end());

		dropN(seqA, nums1.size() - lenA);
		dropN(seqB, nums2.size() - lenB);

		NumList cur = merge(seqA, seqB);
		if (compare(cur, biggest) > 0) {
			biggest = cur;
		}
	}

	return vector<int>(biggest.begin(), biggest.end());
}

int main() {
	//vector<int> arg0 = { 3, 4, 6, 5 };
	//vector<int> arg1 = { 9, 1, 2, 5, 8, 3 };
	//auto ans = maxNumber(arg0, arg1, 5);

	//vector<int> arg0 = { 6, 7 };
	//vector<int> arg1 = { 6, 0, 4 };
	//auto ans = maxNumber(arg0, arg1, 5);

	//vector<int> arg0 = { 3, 9 };
	//vector<int> arg1 = { 8, 9 };
	//auto ans = maxNumber(arg0, arg1, 3);

	vector<int> arg0 = { 6, 3, 9, 0, 5, 6 };
	vector<int> arg1 = { 2, 2, 5, 2, 1, 4, 4, 5, 7, 8, 9, 3, 1, 6, 9, 7, 0 };
	auto ans = maxNumber(arg0, arg1, 23);

	for (auto line : ans) {
		cout << line << endl;
	}

	cin.get();
}