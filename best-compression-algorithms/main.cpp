#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int parseNum(string &line, int begin, int &end) {
	end = begin;

	while (line[end] >= '0' && line[end] <= '9') ++end;

	int result = 0;
	for (int idx = begin; idx < end; ++idx) {
		result += (line[idx] - '0') * pow(10, end - idx - 1);
	}
	
	return result;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		vector<int> stack;
		int totalLen = 0;
		string line;
		cin >> line;

		for (int idx = 0; idx < line.size(); ++idx) {
			char ch = line[idx];
			if (ch == '(') {
				stack.push_back(totalLen);
			}
			else if (ch == ')') {
				int len = stack.back();
				stack.pop_back();
				int end;
				totalLen += (totalLen - len) * (parseNum(line, ++idx, end) - 1);
				idx = end - 1;
			}
			else if (ch >= '0' && ch <= '9'){
				int end;
				totalLen += (parseNum(line, idx, end) - 1);
				idx = end - 1;
			}
			else {
				totalLen++;
			}
		}

		cout << totalLen << endl;
	}
}