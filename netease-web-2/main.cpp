#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

int n, k;

int main() {
	scanf("%d%d", &n, &k);

	if (n == 1){
		printf("0 0");
		return 0;
	}
	
	set<pii> towers;
	for (int i = 0; i < n; ++i){
		int height;
		scanf("%d", &height);
		towers.insert(mp(height, i + 1));
	}

	int unstablization = towers.rbegin()->first - towers.begin()->first;
	vector<pii> actions;

	for (int i = 0; i < k; ++i){
		int top = towers.rbegin()->first;
		int bottom = towers.begin()->first;

		int topPos = towers.rbegin()->second;
		int bottomPos = towers.begin()->second;

		if (top - bottom <= 1){
			break;
		}

		towers.erase(prev(towers.end()));
		towers.erase(towers.begin());

		towers.insert(mp(top - 1, topPos));
		towers.insert(mp(bottom + 1, bottomPos));

		actions.push_back(mp(topPos, bottomPos));

		unstablization = min(unstablization, 
			towers.rbegin()->first - towers.begin()->first);
	}

	printf("%d %d\n", unstablization, (int)actions.size());
	for (pii action : actions){
		printf("%d %d\n", action.first, action.second);
	}
}