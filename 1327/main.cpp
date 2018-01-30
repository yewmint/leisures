#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

int maxIdx(int cnt[26]) {
	int max = 0;
	int idx = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > max) {
			max = cnt[i];
			idx = i;
		}
	}
	return idx;
}

bool isValid(int cnt[26], int left) {
	return cnt[maxIdx(cnt)] * 2 - 1 <= left;
}

int main() {
	string line;
	while (cin >> line) {
		int cnt[26] = { 0 };
		int left = line.size();

		for (char ch : line) {
			cnt[ch - 'a']++;
		}

		if (!isValid(cnt, left)) {
			cout << "INVALID" << endl;
			break;
		}

		string output;
		while (left > 0) {
			for (int i = 0; i < 26; ++i) {
				if (cnt[i] <= 0) {
					continue;
				}

				if (output.size() > 0 && output.back() - 'a' == i) {
					continue;
				}

				cnt[i]--;
				left--;

				if (isValid(cnt, left)) {
					output.push_back(i + 'a');
					break;
				}
				else {
					cnt[i]++;
					left++;
				}
			}
		}

		cout << output << endl;
	}
}