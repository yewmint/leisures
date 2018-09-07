#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int n, k, t;

int main() {
  scanf("%d%d%d", &n, &k, &t);
  vector<int> nums(n);
  for (int i = 0; i < n; ++i){
    int num;
    scanf("%d", &num);
    nums[i] = num;
  }

  map<int, int> numCnt;
  set<pair<int, int>> numSet;
  int cnt = 0;
  int ret = 0;
  
  for (int i = 0; i < n; ++i) {
    int num = nums[i];
    cnt++;

    if (numCnt.count(num) > 0){
      numSet.erase(mp(numCnt[num], num));
      numCnt[num]++;
      numSet.insert(mp(numCnt[num], num));
    }
    else {
      numCnt[num]++;
      numSet.insert(mp(numCnt[num], num));
    }

    if (cnt >= k){
      if (numSet.rbegin()->first >= t){
        ret++;
      }
    }

    if (cnt >= k){
      int last = nums[i - k + 1];
      numSet.erase(mp(numCnt[last], last));
      numCnt[last]--;
      numSet.insert(mp(numCnt[last], last));

      if (numCnt[last] == 0){
        numCnt.erase(last);
        numSet.erase(mp(0, last));
      }

      cnt--;
    }
  }

  printf("%d", ret);
}