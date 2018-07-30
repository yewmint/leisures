#include <bits/stdc++.h>

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

bool isOnCircle(
  const vector<vector<int>>& conns, 
  vector<bool>& visited,
  vector<pii>& vips,
  int root, 
  int node
  ) {
  if (node == root && visited[root]) {
    return true;
  }

  if (visited[node]) return false;
  visited[node] = true;

  for (int next : conns[node]){
    if (isOnCircle(conns, visited, vips, root, next)){
      vips.push_back({node, next});
      return true;
    }
  }

  return false;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
  const int NODE_LEN = edges.size();
  vector<bool> hasParent(NODE_LEN, false);
  for (auto edge : edges){
    if (!hasParent[edge[1]]){
      hasParent[edge[1]] = true;
    }
    else {
      return edge;
    }
  }

  vector<vector<int>> conns(NODE_LEN);
  for (auto edge : edges){
    conns[edge[0]].push_back(edge[1]);
  }

  vector<bool> visited(NODE_LEN, false);
  vector<pii> vips;
  for (int node = 0; node < NODE_LEN; ++node){
    if (!isOnCircle(conns, visited, vips, node, node)) continue;
    int maxPos = -1;
    for (pii vip : vips){
      vector<int> e({ vip.first, vip.second });
      auto it = find(edges.begin(), edges.end(), e);
      maxPos = max<int>(
        maxPos, 
        it - edges.begin()
      );
    }
    
    return edges[maxPos];
  }

  return vector<int>();
}

int main() {
	// vector<vector<int>> arg0 = {{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};
	vector<vector<int>> arg0 = {{1,2},{2,3},{3,4},{4,1},{1,5}};
	
  auto ans = findRedundantDirectedConnection(arg0);
  cout << ans[0] << ", " << ans[1] << endl;

	cout << "finished" << endl;
	cin.get();
}