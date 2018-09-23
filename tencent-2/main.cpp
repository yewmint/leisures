#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int getIn(vector<set<int>> &revEdges, vector<bool> &visited, int cur){
  if (visited[cur]) return 0;

  int ret = 1;
  for (int from : revEdges[cur]){
    if (!visited[cur]) ret += getIn(revEdges, visited, from);
  }

  return ret;
}

int getOut(vector<set<int>> &edges, vector<bool> &visited, int cur){
  if (visited[cur]) return 0;

  int ret = 1;
  for (int from : edges[cur]){
    if (!visited[cur]) ret += getOut(edges, visited, from);
  }

  return ret;
}

int n, m;

int main() {
  scanf("%d%d", &n, &m);

  vector<set<int>> edges(n);
  vector<set<int>> revEdges(n);
  for (int i = 0; i < m; ++i){
    int from, to;
    scanf("%d%d", &from, &to);
    edges[from - 1].insert(to - 1);
    revEdges[to - 1].insert(from - 1);
  }

  vector<int> rets;
  for (int i = 0; i < n; ++i){
    vector<int> inStk = { i };
    vector<bool> inVisited(n, false);
    inVisited[i] = true;
    int inVal = 1;
    while (!inStk.empty()){
      int node = inStk.back();
      inStk.pop_back();

      for (int from : revEdges[node]){
        if (!inVisited[from]){
          inVisited[from] = true;
          inVal++;
          inStk.push_back(from);
        }
      }
    }

    vector<int> outStk = { i };
    vector<bool> outVisited(n, false);
    outVisited[i] = true;
    int outVal = 1;
    while (!outStk.empty()){
      int node = outStk.back();
      outStk.pop_back();

      for (int to : edges[node]){
        if (!outVisited[to]){
          outVisited[to] = true;
          outVal++;
          outStk.push_back(to);
        }
      }
    }

    if (inVal > outVal) {
      rets.push_back(i);
    }
  }

  printf("%d", (int)rets.size());
}