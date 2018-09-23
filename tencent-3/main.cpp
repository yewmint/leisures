#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int t, a, b, c;

int main() {
  scanf("%d", &t);
  while (t--){
    scanf("%d%d%d", &a, &b, &c);
    
    bool found = false;
    for (int i = 1; i < 10000; ++i){
      if ((a * i) % b == c){
        found = true;
        break;
      }
    }

    printf("%s\n", found ? "YES" : "NO");
  }
}