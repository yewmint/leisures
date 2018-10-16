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

int t, a;

int main() {
  scanf("%d", &t);

  while (t--){
    scanf("%d", &a);

    int tmp = a;
    int one = 0;
    while (tmp > 0){
      tmp &= (tmp - 1);
      one++;
    }

    printf("%d\n", 1 + ((0x1 << one) - 1));
  }
}