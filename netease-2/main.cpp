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
#include <stdio.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int T;
char M[150006];

int eval(char *msg, int & l) {
	if (msg[l] != '(') {
		return msg[l] - '0';
	}

	++l;

	if (msg[l] == '!') {
		l++;
		int val = !eval(msg, l);
		l++;
		return val;
	}
	else {
		int lval = eval(msg, l);
		++l;

		char op = msg[l];
		++l;

		int rval = eval(msg, l);
		l++;

		if (op == '&') {
			return lval & rval;
		}
		else {
			return lval | rval;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", &M);

		int l = 0;
		cout << eval(M, l) << endl;
	}
}