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
#include <string.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int N, K;
char str[100006];
int longest[100006];
bool forbid[26][26];
int last[26];

int main() {
	scanf("%d", &N);
	scanf("%s", str + 1);
	scanf("%d", &K);
	while (K--) {
		char tmp[10];
		scanf("%s", tmp);
		forbid[tmp[0] - 'a'][tmp[1] - 'a'] = true;
		forbid[tmp[1] - 'a'][tmp[0] - 'a'] = true;
	}

	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		char cur = str[i];
		int maxLen = 0;
		for (int k = 0; k < 26; ++k) {
			if (!forbid[cur - 'a'][k]) {
				maxLen = max(maxLen, longest[last[k]] + 1);
			}
		}
		last[cur - 'a'] = i;
		longest[i] = maxLen;
		ret = max(ret, maxLen);
	}

	printf("%d", N - ret);
}