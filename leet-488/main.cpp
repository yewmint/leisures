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

string shrink(const string & str) {
	list<pair<char, int>> counts;
	for (const char ch : str) {
		if (counts.size() > 0 && counts.back().first == ch) {
			counts.back().second++;
		}
		else {
			counts.push_back(mp(ch, 1));
		}
	}

	for (auto it = counts.begin(); it != counts.end();) {
		auto nextIt = next(it, 1);

		if (it->second >= 3) {
			counts.erase(it);

			if (nextIt != counts.begin() && nextIt != counts.end()) {
				auto prevIt = prev(nextIt, 1);
				if (prevIt->first == nextIt->first) {
					nextIt->second += prevIt->second;
					counts.erase(prevIt);
				}
			}
		}

		it = nextIt;
	}

	string ret;
	for (auto charCount : counts) {
		ret += string(charCount.second, charCount.first);
	}

	return ret;
}

int findMinStep(string board, string hand) {
	if (board.empty()) {
		return 0;
	}

	if (hand.empty()) {
		return -1;
	}

	int minStep = -1;
	for (int boardIdx = 0; boardIdx < board.size(); ++boardIdx) {
		if (boardIdx >= 1 && board[boardIdx] == board[boardIdx - 1]) {
			continue;
		}

		for (int handIdx = 0; handIdx < hand.size(); ++handIdx) {
			const char curBall = hand[handIdx];

			string insertedBoard = string(board);
			insertedBoard.insert(insertedBoard.begin() + boardIdx, curBall);

			string nextBoard = shrink(insertedBoard);
			string nextHand = string(hand).erase(handIdx);

			int nextStep = findMinStep(nextBoard, nextHand);
			if (nextStep >= 0) {
				minStep = minStep == -1 ? nextStep + 1 : min(minStep, nextStep + 1);
			}
		}
	}

	return minStep;
}

int main() {
	cout << findMinStep("RBYYBBRRB", "YRBGB") << endl;
	cout << findMinStep("WWRRBBWW", "WRBRW") << endl;
	cout << findMinStep("WRRBBW", "RB") << endl;
	cout << findMinStep("G", "GGGGG") << endl;

	cin.get();
}