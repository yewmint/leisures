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
  vector<vector<int>> mat(n, vector<int>(n, 0));
  for (int row = 0; row < n; ++row){
    for (int col = 0; col < n; ++col){
      int num;
      scanf("%d", &num);
      mat[row][col] = num;
    }
  }

  int ret = 0;

  for (int row = 0; row < n; ++row){
    for (int col = 0; col < n; ++col){
      if (mat[row][col] == 1){
        ret++;

        mat[row][col] = 0;
        vector<pii> stk({{ row, col }});

        while (!stk.empty()){
          pii root = stk.back();
          stk.pop_back();

          int dirs[] = { 1, 0, -1, 0, 1 };
          for (int i = 0; i < 4; ++i){
            int newRow = root.first + dirs[i];
            int newCol = root.second + dirs[i + 1];
            
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n){
              if (mat[newRow][newCol] == 1){
                mat[newRow][newCol] = 0;
                stk.push_back({ newRow, newCol });
              }
            }
          }
        }
      }
    }
  }

  printf("%d", ret);
}