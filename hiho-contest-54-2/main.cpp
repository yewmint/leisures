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

int main() {
	string str;
	cin >> str;

	int pos = str.size() / 2;
	for (int i = 0; i < str.size() / 2; ++i) {
		int j = str.size() - i - 1;
		if (str[i] != str[j]) {
			string tmp = str;
			tmp.erase(i, 1);
			string rev(tmp.rbegin(), tmp.rend());

			if (tmp == rev) {
				pos = i;
			}
			else {
				pos = j;
			}
			break;
		}
	}

	while (pos > 0 && str[pos - 1] == str[pos]) {
		pos--;
	}

	cout << pos + 1;
}