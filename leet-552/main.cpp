#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int checkRecord(int n) {
	vector<vector<int>> counts(n + 1, vector<int>(3, 0));

	counts[1][0] = 1;
	counts[1][1] = 1;
	counts[1][2] = 0;

	for (int i = 2; i <= n; ++i){
		counts[i][0] = counts[i - 1][0] + counts[i - 1][1] + counts[i - 1][2];
		counts[i][1] = counts[i - 1][0];
		counts[i][2] = counts[i - 1][1];

		counts[i][0] %= static_cast<int>(1e9 + 7);
		counts[i][1] %= static_cast<int>(1e9 + 7);
		counts[i][2] %= static_cast<int>(1e9 + 7);
	}

	int result = counts[n][0] + counts[n][1] + counts[n][2];
	result %= static_cast<int>(1e9 + 7);
	for (int i = 1; i <= n; ++i){
		int lhs = counts[i - 1][0] + counts[i - 1][1] + counts[i - 1][2];
		int rhs = counts[n - i][0] + counts[n - i][1] + counts[n - i][2];

		lhs = max<int>(lhs, 1);
		rhs = max<int>(rhs, 1);

		result += lhs * rhs;
		result %= static_cast<int>(1e9 + 7);	
	}

	return result % static_cast<int>(1e9 + 7);
}

int main() {
	// cout << checkRecord(1) << endl;
	// cout << checkRecord(2) << endl;
	cout << checkRecord(100) << endl;
	cout << "finished" << endl;
	cin.get();
}