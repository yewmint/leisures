#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

// void traverse(
//   vector<vector<pii>> &edges,
//   vector<unordered_map<int, int>> &ways,
//   vector<bool> &visited,
//   vector<vector<pii>> &specVals,
//   int curCity,
//   int cost,
//   int road
// ) {
//   for (pii nextCityCost : edges[curCity]){
//     int nextCity = nextCityCost.first;
//     int curCost = nextCityCost.second;

//     if (visited[nextCity]) continue;
//     visited[nextCity] = true;

//     if (ways[nextCity].count(road + 1) > 0){
//       ways[nextCity][road + 1] = min(ways[nextCity][road + 1], cost + curCost);
//     }
//     else {
//       ways[nextCity][road + 1] = cost + curCost;
//     }    

//     if (cost + curCost < specVals[nextCity][0].first){
//       specVals[nextCity][0] = mp(cost + curCost, road + 1);
//     }
//     if (road + 1 < specVals[nextCity][1].second){
//       specVals[nextCity][1] = mp(cost + curCost, road + 1);
//     }
  
//     traverse(edges, ways, visited, specVals, nextCity, cost + curCost, road + 1);

//     visited[nextCity] = false;
//   }
// }

int n, m, q;

int main() {
  scanf("%d%d%d", &n, &m, &q);

  vector<vector<pii>> edges(n + 1, vector<pii>());
  for (int i = 1; i <= m; ++i){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    edges[x].push_back(mp(y, z));
    edges[y].push_back(mp(x, z));
  }

  vector<unordered_map<int, int>> ways(n + 1, unordered_map<int, int>());
  vector<vector<pii>> specVals(n + 1, vector<pii>({ { INT_MAX, 0 }, { 0, INT_MAX } }));
  vector<bool> visited(n + 1, false);
  visited[1] = true;

  // traverse(edges, ways, visited, specVals, 1, 0, 0);

  vector<vector<int>> stk = { { 1, 0, 0 } };

  while (!stk.empty()){
    int curCity = stk.back()[0];
    int cost = stk.back()[1];
    int road = stk.back()[2];
    stk.pop_back();

    if (cost == -1){
      visited[curCity] = false;
      continue;
    }

    visited[curCity] = true;
    stk.push_back({ curCity, -1, -1 });

    for (pii nextCityCost : edges[curCity]){
      int nextCity = nextCityCost.first;
      int curCost = nextCityCost.second;

      if (visited[nextCity]) continue;

      if (ways[nextCity].count(road + 1) > 0){
        ways[nextCity][road + 1] = min(ways[nextCity][road + 1], cost + curCost);
      }
      else {
        ways[nextCity][road + 1] = cost + curCost;
      }

      stk.push_back({ nextCity, cost + curCost, road + 1 });
    }
  }

  // for (int i = 1; i <= n; ++i){
  //   for (pii way : ways[i]){
  //     ll road = way.first;
  //     ll cost = way.second;

  //     minWays[i][road] = cost;
  //   }
  // }

  while (q--){
    int j, i;
    scanf("%d%d", &j, &i);

    if (j == 1){
      printf("0\n");
      continue;
    }

    ll minCost = LLONG_MAX;
    for (auto it = ways[j].begin(); it != ways[j].end(); ++it){
      ll road = it->first;
      ll cost = it->second;

      ll curCost = cost + road * i;
      minCost = min(minCost , curCost);

      // auto nextIt = next(it);
      // if (nextIt != ways[j].end()){
      //   if (scll(nextIt->first - road) * i > cost){
      //     break;
      //   }
      // }
    }

    // for (int x = 0; x <= 1; ++x){
    //   ll cost = specVals[j][x].first;
    //   ll road = specVals[j][x].second;

    //   ll curCost = cost + road * i;
    //   minCost = min(minCost , curCost);
    // }

    // for (int road = 1; road < m; ++road){
    //   ll cost = minWays[j][road];
    //   if (cost == -1) continue;

    //   ll curCost = cost + road * i;
    //   minCost = min(minCost, curCost);
    // }

    printf("%lld\n", minCost);
  }
}