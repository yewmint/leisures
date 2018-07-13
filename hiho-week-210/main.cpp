#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 10006
int N, M;
int A[MAXN], P[MAXN], S[MAXN];

void readArray(int *array){
	for (int i = 0; i < M; ++i){
		scanf("%d", array + i);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	readArray(A);
	readArray(P);
	readArray(S);

	set<pair<ll, int>> bundles;
	for (int i = 0; i < M; ++i){
		int amount = A[i] >= S[i] ? S[i] : A[i];
		A[i] -= amount;
		bundles.insert(mp(static_cast<ll>(amount) * static_cast<ll>(P[i]), i));
	}

	ll result = 0;
	int remainSlot = N;
	while (remainSlot > 0 && bundles.size() > 0){
		ll maxPrice = bundles.rbegin()->first;
		int index = bundles.rbegin()->second;
		bundles.erase(--bundles.end());

		result += maxPrice;
		int nextAmount = A[index] >= S[index] ? S[index] : A[index];
		A[index] -= nextAmount;
		if (nextAmount > 0){
			bundles.insert(mp(
				static_cast<ll>(nextAmount) * static_cast<ll>(P[index]), 
				index
			));
		}

		remainSlot--;
	}

	printf("%lld", result);
}