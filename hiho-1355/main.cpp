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

using namespace std;

// WA
int main() {
	long long N, M;
	cin >> N >> M;

	vector<string> words;
	string line;
	while (cin >> line) {
		words.push_back(line);
	}

	vector<pair<long long, bool>> headSeq;
	vector<long long> timeSeq;
	set<pair<long long, bool>> headSet;
	pair<long long, bool> loopHead;

	long long sentLen = -1;
	for (string &word : words) {
		sentLen += word.size() + 1;
	}

	long long curRow = 0;
	long long curCol = 0;
	long long timeLeft = N;
	long long curWordIdx = 0;
	bool needSpace = false;
	bool isLastLineEmpty = false;

	while (timeLeft > 0) {
		timeSeq.push_back(N - timeLeft);

		auto head = make_pair(curWordIdx, needSpace);
		if (headSet.count(head) == 1) {
			loopHead = head;
			break;
		}
		else {
			headSeq.push_back(head);
			headSet.insert(head);
		}

		curCol = 0;
		isLastLineEmpty = true;

		if (needSpace) {
			curCol++;
			needSpace = false;
		}

		while (M - curCol >= words[curWordIdx].size()) {
			isLastLineEmpty = false;
			curCol += words[curWordIdx].size();
			if (++curWordIdx >= words.size()) {
				curWordIdx = 0;
				if (--timeLeft <= 0) {
					break;
				}
				else {
				}
			}

			if (curCol == M) {
				needSpace = true;
			}
			else {
				curCol++;

				if (curWordIdx == 0) {
					long long left = M - curCol;
					long long passNum = left / (sentLen + 1);
					passNum = min(passNum, timeLeft);
					curCol += passNum * (sentLen + 1);
					timeLeft -= passNum;

					if (timeLeft <= 0) {
						curCol--;
						break;
					}
				}
			}
		}

		curRow++;
	}

	if (timeLeft == 0) {
		cout << curRow << " " << curCol;
	}
	else {
		auto headIt = find(headSeq.begin(), headSeq.end(), loopHead);
		long long loopRowNum = headSeq.end() - headIt;
		long long loopBeginRow = headSeq.size() - loopRowNum;
		long long loopBeginTimes = timeSeq[timeSeq.size() - loopRowNum - 1];
		long long loopTimeNum = timeSeq.back() - loopBeginTimes;

		long long baseRow = loopBeginRow + (N - loopBeginTimes) / loopTimeNum * loopRowNum;

		// curCol--;
		curRow = 0;
		timeLeft = (N - loopBeginTimes) % loopTimeNum;
		auto beginHead = headSeq[loopBeginRow];
		curWordIdx = beginHead.first;
		needSpace = beginHead.second;

		while (timeLeft > 0) {
			curCol = 0;

			if (needSpace) {
				curCol++;
				needSpace = false;
			}

			while (M - curCol >= words[curWordIdx].size()) {
				curCol += words[curWordIdx].size();
				if (++curWordIdx >= words.size()) {
					curWordIdx = 0;
					if (--timeLeft <= 0) {
						break;
					}
				}

				if (curCol == M) {
					needSpace = true;
				}
				else {
					curCol++;

					if (curWordIdx == 0) {
						long long left = M - curCol;
						long long passNum = left / (sentLen + 1);
						passNum = min(passNum, timeLeft);
						curCol += passNum * (sentLen + 1);
						timeLeft -= passNum;

						if (timeLeft <= 0) {
							curCol--;
							break;
						}
					}
				}
			}

			curRow++;
		}

		if (isLastLineEmpty) {
			curRow--;
		}

		cout << baseRow + curRow << " " << curCol;
	}
}