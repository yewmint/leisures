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

int S(ll x){
  int ret = 0;
  while (x > 0){
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  scanf("%lld", &n);

  ll cur = 9;
  ll remain = n;
  while (cur < remain){
    cur = cur * 10 + 9;
  }

  cur /= 10;

  ll b = cur;
  ll a = n - b;

  int ret = S(a) + S(b);

  printf("%d", ret);
}