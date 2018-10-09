#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int n;
char str[106];

int main() {
  scanf("%d", &n);
  scanf("%s", str);

  int is8 = 0;
  for (int i = 0; i < n; ++i){
    if (str[i] == '8') is8++;
  }

  int ret = 0;
  while (is8 > 0 && n >= 11){
    is8--;
    n -= 11;
    ret++;
  }

  printf("%d", ret);
}