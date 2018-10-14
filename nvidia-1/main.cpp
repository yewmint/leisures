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

int n, x0, yy0;

int main() {
  while (scanf("%d%d%d", &n, &x0, &yy0) != EOF){
    bool perpen = false;
    set<double> slopes;

    while (n--){
      int x1, y1;
      scanf("%d%d", &x1, &y1);

      double dx = x1 - x0;
      double dy = y1 - yy0;

      if (dx == 0) {
        perpen = true;
        continue;
      }

      double slope = dy / dx;
      slopes.insert(slope);
    }

    printf("%d\n", sci(slopes.size()) + (perpen ? 1 : 0));
  }
}