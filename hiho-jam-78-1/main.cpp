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
  scanf("%d%d", &n, &m);

  if (m > 2 * (n + 1) || n > 2 * (m + 1)){
    printf("-1");
    return 0;
  }

  string ret;
  while (n > 0 && m > 0){
    if (n > m){
      ret += string("AAB");
      n -= 2;
      m -= 1;
    }
    else if (m > n){
      ret += string("ABB");
      n -= 1;
      m -= 2;
    }
    else {
      ret += string("AB");
      n -= 1;
      m -= 1;
    }
  }

  while (n > 0){
    ret += string("A");
    n--;
  }

  while (m > 0){
    ret = string("B") + ret;
    m--;
  }

  printf("%s", ret.c_str());
}