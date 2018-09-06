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

int totalPath(vector<vector<int>> &nodes, int curNode){
  int total = 0;
  for (int child : nodes[curNode]){
    total += totalPath(nodes, child);
  }
  return total + 2;
}

int longestPath(vector<vector<int>> &nodes, int curNode){
  int longest = 0;
  for (int child : nodes[curNode]){
    longest = max(longest, longestPath(nodes, child));
  }
  return longest + 1;
}

int main() {
  scanf("%d", &n);
  vector<vector<int>> nodes(n, vector<int>());
  for (int i = 0; i < n - 1; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    nodes[a - 1].push_back(b - 1);
  }

  int total = totalPath(nodes, 0);
  int longest = longestPath(nodes, 0);

  printf("%d", total - longest - 1);
}