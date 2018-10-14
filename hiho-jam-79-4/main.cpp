#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

template<typename T>
int sci(T val){
  return static_cast<int>(val);
}

int N, K;
ll methods[1006][2006][4];
const ll D = 998244353;

ll minMethods(int n, int k, int type){
  if (n <= 0) return 0;
  if (k <= 0) return 0;
  if (n * 2 < k) return 0;

  if (n * 2 == k){
    if (type == 1 || type == 2) return 1;
    else return 0;
  }

  if (methods[n][k][type] != 0){
    return methods[n][k][type] == -1 ? 0 : methods[n][k][type];
  }

  ll method = 0;

  if (type == 0){
    method += minMethods(n - 1, k, 0);
    method += minMethods(n - 1, k, 1);
    method += minMethods(n - 1, k, 2);
    method += minMethods(n - 1, k - 1, 3);
  }
  else if (type == 1){
    method += minMethods(n - 1, k - 1, 0);
    method += minMethods(n - 1, k, 1);
    method += minMethods(n - 1, k - 2, 2);
    method += minMethods(n - 1, k - 1, 3);
  }
  else if (type == 2){
    method += minMethods(n - 1, k - 1, 0);
    method += minMethods(n - 1, k - 2, 1);
    method += minMethods(n - 1, k, 2);
    method += minMethods(n - 1, k - 1, 3);
  }
  else if (type == 3){
    method += minMethods(n - 1, k - 1, 0);
    method += minMethods(n - 1, k, 1);
    method += minMethods(n - 1, k, 2);
    method += minMethods(n - 1, k, 3);
  }

  method %= D;
  methods[n][k][type] = method;
  return method;
}

int main() {
  scanf("%d%d", &N, &K);

  for (int i = 1; i <= K; ++i){
    for (int j = 0; j < 4; ++j){
      methods[0][i][j] = -1;
      methods[1][i][j] = -1;
    }
  }

  methods[1][1][0] = 1;
  methods[1][1][1] = -1;
  methods[1][1][2] = -1;
  methods[1][1][3] = 1;

  methods[1][2][0] = -1;
  methods[1][2][1] = 1;
  methods[1][2][2] = 1;
  methods[1][2][3] = -1;

  ll ret = 0;
  ret += minMethods(N, K, 0);
  ret += minMethods(N, K, 1);
  ret += minMethods(N, K, 2);
  ret += minMethods(N, K, 3);
  ret %= D;

  printf("%lld", ret);
}