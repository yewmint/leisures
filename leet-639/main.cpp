#include <bits/stdc++.h>

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const ll MOD = 1e9 + 7;

int numDecodings(string s) {
	vector<ll> count(s.size() + 1, 1);
	string str = string("#") + s;

	for (int idx = 1; idx < str.size(); ++idx){
		char cur = str[idx];
		char prev = str[idx - 1];

		if (cur == '0'){
			if (prev == '1' || prev == '2'){
				count[idx] = count[idx - 2];
			}
			else if (prev == '*'){
				count[idx] = 2 * count[idx - 2] % MOD;
			}
			else {
				return 0;
			}
		}
		else if (cur - '0' >= 1 && cur - '0' <= 6){
			count[idx] = count[idx - 1];

			if (prev == '1' || prev == '2'){
				count[idx] += count[idx - 2];
			}
			else if (prev == '*'){
				count[idx] += 2 * count[idx - 2] % MOD;
			}
		}
		else if (cur - '0' >= 7 && cur - '0' <= 9){
			count[idx] = count[idx - 1];

			if (prev == '1' || prev == '*'){
				count[idx] += count[idx - 2];
			}
		}
		else if (cur == '*'){
			count[idx] = 9 * count[idx - 1] % MOD;

			if (prev == '1'){
				count[idx] += 9 * count[idx - 2] % MOD;
			}
			else if (prev == '2'){
				count[idx] += 6 * count[idx - 2] % MOD;
			}
			else if (prev == '*'){
				count[idx] += 15 * count[idx - 2] % MOD;
			}
		}
	}

	return count[str.size() - 1] % MOD;
}

int main() {
	// cout << numDecodings("1*") << endl;
	cout << numDecodings("**********1111111111") << endl;

	cout << "finished" << endl;
	cin.get();
}