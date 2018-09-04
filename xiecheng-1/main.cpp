#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

ll n, m;

int main() {
	scanf("%lld%lld", &n, &m);

	printf("%lld", n / 2 * m);
}