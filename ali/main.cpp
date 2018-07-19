#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(){
  scanf("%d%d", &N, &M);
  vector<vector<int>> deps(N, vector<int>());
  vector<int> nums(N, 0);
  vector<int> times(N, 0);
  vector<int> toTimes(N, 0);
  vector<int> linkNums(N, 0);

  for (int i = 0; i < N; ++i){
    scanf("%d", &times[i]);
  }

  for (int i = 0; i < M; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    deps[a - 1].push_back(b - 1);
    nums[b - 1]++;
  }

  vector<int> nextNodes;
  for (int i = 0; i < M; ++i){
    if (nums[i] == 0) {
      nextNodes.push_back(i);
      linkNums[i] = 1;
    }
  }

  int linkNum = 0, maxTime = 0;

  while (!nextNodes.empty()){
    int curNode = nextNodes.back();
    nextNodes.pop_back();

    if (deps[curNode].empty()){
      linkNum += linkNums[curNode];
      maxTime = max(maxTime, toTimes[curNode] + times[curNode]);
    }

    for (int tmpNode : deps[curNode]){
      toTimes[tmpNode] = toTimes[curNode] + times[curNode];
      linkNums[tmpNode] += linkNums[curNode];
      nums[tmpNode]--;
      if (nums[tmpNode] == 0){
        nextNodes.push_back(tmpNode);
      }
    }
  }

  printf("%d %d", linkNum, maxTime);
}