#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

int n, m;

int main() {
	scanf("%d", &n);
	vector<int> sums(n);
	int sum = 0;
	for (int i = 0; i < n; ++i){
		int a;
		scanf("%d", &a);
		sum += a;
		sums[i] = sum;
	}

	scanf("%d", &m);
	while (m--){
		int q;
		scanf("%d", &q);

		int rank = lower_bound(sums.begin(), sums.end(), q) - sums.begin() + 1;
		printf("%d\n", rank);
	}
}