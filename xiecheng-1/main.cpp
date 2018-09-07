#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

ll n;

int main() {
	scanf("%lld", &n);
    int ret = 0;
		bool rev = false;
    
    if (n < 0){
        n ^= 0xffffffffffffffffll;
				rev = true;
    }
    
    while (n > 0){
        ret++;
        n &= (n - 1);
    }
    printf("%d", rev ? 64 - ret : ret);
}