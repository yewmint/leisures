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
  vector<vector<int>> edges(m, vector<int>());
  for (int i = 0; i < m; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    edges[b - 1].push_back(a - 1);
  }

  set<int> hots;
  for (int i = 0; i < n; ++i){

    vector<bool> visited(n, false);
    visited[i] = true;
    int visitNum = 1;
    vector<int> stk = { i };

    bool isHot = false;
    while (!stk.empty()){
      int node = stk.back();
      stk.pop_back();
      for (auto & child : edges[node]){
        if (hots.count(child) > 0){
          isHot = true;
          break;
        }

        if (!visited[child]){
          visited[child] = true;
          stk.push_back(child);
          visitNum++;
        }
      }

      if (isHot){
        break;
      }
    }

    if (isHot || visitNum == n){
      hots.insert(i);
    }
  }

  printf("%d", hots.size());
}