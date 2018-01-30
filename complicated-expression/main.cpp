#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

struct OP {
	char optr;
	int argc;
	OP(char op) : optr(op), argc(0) {};
};

long long parseNum(string &line, int begin, int &end) {
	end = begin;

	while (line[end + 1] >= '0' && line[end + 1] <= '9') ++end;

	long long result = 0;
	for (int idx = begin; idx <= end; ++idx) {
		result += (line[idx] - '0') * pow(10, end - idx);
	}

	return result;
}

int main() {
	int T;
	cin >> T;
	getchar();

	while (T--) {
		string line;
		getline(cin, line);
		if (line.size() == 0) continue;

		vector<OP> ops;
		vector<long long> nums;

		bool isInvalid = false;
		for (int idx = 0; idx < line.size(); ++idx) {
			char ch = line[idx];
			if (ch == '(') {
				OP op(line[++idx]);
				if (op.optr != '+' && op.optr != '-' && op.optr != '*') {
					isInvalid = true;
					break;
				}
				ops.push_back(op);
			}
			else if (ch == ')') {
				if (ops.empty()) {
					isInvalid = true;
					break;
				}
				OP op = ops.back();
				ops.pop_back();
				if (!ops.empty()) {
					ops.back().argc++;
				}
				if (op.optr == '+') {
					long long result = 0;
					for (int j = 0; j < op.argc; ++j) {
						result += nums.back();
						nums.pop_back();
					}
					nums.push_back(result);
				}
				else if (op.optr == '-') {
					if (op.argc == 1) {
						nums.back() *= -1;
					}
					else if (op.argc == 2) {
						nums[nums.size() - 2] -= nums.back();
						nums.pop_back();
					}
					else {
						isInvalid = true;
						break;
					}
				}
				else {
					long long result = 1;
					for (int j = 0; j < op.argc; ++j) {
						result *= nums.back();
						nums.pop_back();
					}
					nums.push_back(result);
				}
			}
			else if (ch >= '0' && ch <= '9') {
				int end;
				long long num = parseNum(line, idx, end);
				idx = end;
				nums.push_back(num);
				ops.back().argc++;
			}
		}

		if (isInvalid) {
			cout << "invalid expression" << endl;
		}
		else {
			cout << nums.back() << endl; 
		}
	}
}