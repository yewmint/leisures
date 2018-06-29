#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int findMinMoves(vector<int>& machines) {
	const int len = machines.size();
	vector<int> sums(len + 1, 0);
	int sumSoFar = 0;
	for (int i = 0; i < len; ++i){
		sumSoFar += machines[i];
		sums[i + 1] = sumSoFar;
	}

	if (sums[len] % len != 0){
		return -1;
	}

	int eachVal = sums[len] / len;

	int ret = 0;
	for (int i = 1; i <= len; ++i){
		int left = sums[i - 1];
		int right = sums[len] - sums[i];
		int cur = machines[i];

		int leftExpected = eachVal * (i - 1);
		int rightExpected = eachVal * (len - i);

		int aOut = leftExpected - left;
		int bOut = rightExpected - right;

		if (aOut > 0 && bOut > 0){
			ret = max(ret, aOut + bOut);
		}
		else {
			ret = max(ret, max(abs(aOut), abs(bOut)));
		}
	}

	return ret;
}

int main() {
	// vector<int> arg0 = { 1, 3, 0, 6, 5 };
	// vector<int> arg0 = { 1, 0, 5 };
	// vector<int> arg0 = { 0, 3, 0 };
	vector<int> arg0 = { 1 };
	cout << findMinMoves(arg0) << endl;
	cout << "finished" << endl;
	cin.get();
}