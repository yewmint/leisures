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

int main() {
  scanf("%d", &n);
  vector<vector<int>> goods(n, vector<int>(3, 0));
  for (int i = 0; i < n; ++i){
    scanf("%d%d%d", &goods[i][0], &goods[i][1], &goods[i][2]);
  }

  int ret = 0;
  for (int i = 0; i < n; ++i){
    bool isBad = false;
    for (int j = 0; j < n && !isBad; ++j){
      if (goods[i][0] < goods[j][0] && 
        goods[i][1] < goods[j][1] && 
        goods[i][2] < goods[j][2]) {
        ret++;
        isBad = true;
      }
    }
  }

  printf("%d", ret);
}