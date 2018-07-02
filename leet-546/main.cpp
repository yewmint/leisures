#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int removeBoxes(vector<int>& boxes) {
	vector<pii> seqs;
	int last = 0, count = 0;
	for (auto box : boxes){
		if (last != box){
			if (count > 0) seqs.push_back(mp(last, count));
			last = box;
			count = 0;
		}
		else {
			count++;
		}
	}

	map<vector<pii>, int> seqVal;
}

int main() {
	// vector<int> arg0 = { 1, 3, 2, 2, 2, 3, 4, 3, 1 };
	vector<int> arg0 = { 1, 3, 1 };
	cout << removeBoxes(arg0) << endl;
	cout << "finished" << endl;
	cin.get();
}