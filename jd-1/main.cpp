#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int T, N, M, X, Y;

int main() {
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &N, &M);
    vector<vector<int>> groups;
    vector<set<int>> edges(N, set<int>());
    while (M--) {
      scanf("%d%d", &X, &Y);
      edges[X - 1].insert(Y - 1);
      edges[Y - 1].insert(X - 1);
    }

    bool isBad = false;
    for (int node = 0; node < N && !isBad; ++node){
      bool inserted = false;

      for (auto &group : groups){
        int edgeWithGroup = 0;
        for (int groupNode : group){
          if (edges[node].count(groupNode) > 0){
            edgeWithGroup++;
          }
        }
        if (edgeWithGroup == 0){
          if (inserted){
            isBad = true;
            break;
          }
          else {
            group.push_back(node);
            inserted = true;
          }
        }
        else if (edgeWithGroup < group.size()){
          isBad = true;
          break;
        }
      }

      if (!inserted){
        groups.push_back(vector<int>({ node }));
      }
    }
    
    printf("%s\n", isBad ? "No" : "Yes");
  }
}