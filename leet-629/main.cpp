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

int kInversePairs(int n, int k) {
	vector<vector<ll>> revCount(n + 1, vector<ll>(k + 1, 0));
	revCount[1][0] = 1;

	for (int num = 2; num <= n; ++num){
		ll sum = 0;
		for (int rev = 0; rev <= k; ++rev){
			sum += revCount[num - 1][rev];
			if (rev >= num) {
				sum -= revCount[num - 1][rev - num];
				if (sum == 0) break;
			}

			revCount[num][rev] = sum % 1000000007;
		}
	}

	return revCount[n][k] % 1000000007;
}

int main() {
	// cout << kInversePairs(3, 0) << endl;
	// cout << kInversePairs(3, 1) << endl;
	cout << kInversePairs(1000, 1000) << endl;

	cout << "finished" << endl;
	cin.get();
}