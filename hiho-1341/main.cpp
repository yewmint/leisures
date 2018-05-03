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
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <stdio.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

struct Constraint {
	int aval, bval;
	char avar, bvar;
	bool isAvar, isBvar;
	bool isEqual;
	Constraint(int aval, int bval, char avar, char bvar, bool isAvar, bool isBvar, bool isEqual) : 
		aval(aval), bval(bval), avar(avar), bvar(bvar), isAvar(isAvar), isBvar(isBvar), isEqual(isEqual) {};
};

int main() {
	int N;
	scanf("%d", &N);
	vector<Constraint> constraints;
	set<char> vars;

	for (int i = 0; i < N; ++i) {
		string cons;
		cin >> cons;

		bool isAvar = false, isBvar = false;
		int aval = 0, bval = 0;
		char avar = 0, bvar = 0;
		bool isEqual = false;

		int j = 0;
		if (cons[j] >= 'A' && cons[j] <= 'Z') {
			isAvar = true;
			avar = cons[j];
			vars.insert(avar);
			++j;
		}
		else {
			aval = 0;
			while (cons[j] >= '0' && cons[j] <= '9') {
				aval = aval * 10 + (cons[j] - '0');
				++j;
			}
		}

		while (j < cons.size()) {
			isEqual = cons[++j] == '=';
			j += cons[j] == '=' ? 1 : 0;

			if (cons[j] >= 'A' && cons[j] <= 'Z') {
				isBvar = true;
				bvar = cons[j];
				vars.insert(bvar);
				++j;
			}
			else {
				isBvar = false;
				bval = 0;
				while (j < cons.size() && cons[j] >= '0' && cons[j] <= '9') {
					bval = bval * 10 + (cons[j] - '0');
					++j;
				}
			}

			constraints.push_back(Constraint(aval, bval, avar, bvar, isAvar, isBvar, isEqual));

			aval = bval;
			avar = bvar;
			isAvar = isBvar;
		}		
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		map<char, int> varVals;
		for (int i = 0; i < vars.size(); ++i) {
			char var;
			int val;
			cin >> var >> val;
			varVals[var] = val;
		}

		bool satisfied = true;
		for (auto con : constraints) {
			int a = con.isAvar ? varVals[con.avar] : con.aval;
			int b = con.isBvar ? varVals[con.bvar] : con.bval;

			if ((con.isEqual && a > b) || (!con.isEqual && a >= b)) {
				satisfied = false;
				break;
			}
		}

		if (satisfied) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}