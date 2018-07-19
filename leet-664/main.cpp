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

int printer(const string & str, vector<vector<int>> & dp, int left, int right){
	if (right <= left) return 0;
	if (dp[left][right] > 0) return dp[left][right];

	char printChar = str[left];
	int leftPt = left, rightPt = right;
	while (leftPt < right && str[leftPt] == printChar) leftPt++;
	while (rightPt > left && str[rightPt - 1] == printChar) rightPt--;

	dp[left][right] = 1 + printer(str, dp, leftPt, rightPt);
	for (int i = leftPt; i < rightPt; ++i){
		if (str[i] == printChar){
			dp[left][right] = min(
				dp[left][right], 
				printer(str, dp, leftPt, i) + printer(str, dp, i, rightPt)
			);
			while (i < right && str[i] == printChar) i++;
		}
	}
	
	return dp[left][right];
}

int strangePrinter(string s) {
	vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
	return printer(s, dp, 0, s.size());
}

int main() {
	cout << strangePrinter("aaabbb") << endl;
	// cout << strangePrinter("caabbac") << endl;

	cout << "finished" << endl;
	cin.get();
}