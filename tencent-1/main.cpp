#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int n;

int gcd(int a, int b) { 
  if (b == 0) return a; 
  return gcd(b, a % b); 
}

int main() {
  scanf("%d", &n);

  list<int> remains;
  for (int i = 2; i <= n; ++i){
    remains.push_back(i);
  }

  int m = n + 1;
  while (m < n * 2){
    int tmp = m;
    for (auto it = remains.begin(); it != remains.end();){
      int val = *it;
      int gcdVal = gcd(tmp, val);
      it++;

      if (gcdVal != 1){
        remains.erase(prev(it));
        tmp /= gcdVal;

        if (val != gcdVal){
          remains.push_back(val / gcdVal);
        }
      }
    }

    if (remains.empty()) break;
    m++;
  }

  printf("%d", m);
}