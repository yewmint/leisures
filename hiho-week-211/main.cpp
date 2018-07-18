#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

#define MAXN 100006
int N, A[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		scanf("%d", &A[i]);
	}

	ll result = 0;
	for (int i = 0; i < 31; ++i){
		int oneCount = 0;
		for (int j = 0; j < N; ++j){
			if (A[j] & 0x1 == 0x1) {
				oneCount++;
			}
			A[j] >>= 1;
		}

		result += scll(oneCount) * scll(N - oneCount);
	}

	printf("%lld", result);
}