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

int a, b, c;

int main() {
  scanf("%d%d%d", &a, &b, &c);

  if (a < b) swap(a, b);
  if (a < c) swap(a, c);

  printf("%d", a >= b + c ? a - b - c + 1 : 0);
}