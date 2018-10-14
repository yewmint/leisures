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

int N, D;

vector<int> children[100006];
vector<int> path;
vector<int> result(100006, -2);

void traverse(
  int curLevel,
  int curNode
) {
  if (curLevel <= D){
    result[curNode] = -1;
  }
  else {
    result[curNode] = path[curLevel - D - 1];
  }

  path.push_back(curNode);

  for (int child : children[curNode]){
    traverse(curLevel + 1, child);
  }

  path.pop_back();
}

int main() {
  scanf("%d%d", &N, &D);

  for (int i = 2; i <= N; ++i){
    int boss;
    scanf("%d", &boss);
    children[boss].push_back(i);
  }

  traverse(1, 1);

  for (int i = 1; i <= N; ++i){
    printf("%d\n", result[i]);
  }
}