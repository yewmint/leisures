#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int findRotateSteps(string ring, string key) {
	if (ring.size() == 1){
		return key.size();
	}

	vector<int> numPoses[26];
	for (int i = 0; i < ring.size(); ++i){
		numPoses[ring[i] - 'a'].push_back(i);
	}

	vector<vector<int>> moveElemStep(
		ring.size() + 1, 
		vector<int>(key.size() + 1, INT_MAX)
	);

	int head = key[0] - 'a';
	for (int pos : numPoses[head]){
		int minMove = min<int>(pos, ring.size() - pos);
		moveElemStep[pos][0] = minMove + 1;
	}

	for (int i = 1; i < key.size(); ++i){
		int cur = key[i] - 'a';
		int pre = key[i - 1] - 'a';
		for (int curPos : numPoses[cur]){
			for (int prePos : numPoses[pre]){
				int dis = min<int>(
					abs(curPos - prePos), 
					ring.size() - abs(curPos - prePos)
				);
				moveElemStep[curPos][i] = min(
					moveElemStep[curPos][i], 
					moveElemStep[prePos][i - 1] + dis + 1
				);
			}
		}
	}

	int ret = INT_MAX;
	for (int pos : numPoses[key.back() - 'a']) {
		ret = min(ret, moveElemStep[pos][key.size() - 1]);
	}

	return ret;
}

int main() {
	cout << findRotateSteps("godding", "gd") << endl;
	cout << "finished" << endl;
	cin.get();
}