#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int n, m, x;
int a[2006], b[2006];
int asum[2006], bsum[2006];
int alensum[2006], blensum[2006];

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    asum[i] = asum[i - 1] + a[i];
  }
  for (int i = 1; i <= m; ++i){
    scanf("%d", &b[i]);
    bsum[i] = bsum[i - 1] + b[i];
  }
  scanf("%d", &x);
  
  for (int rowa = 1; rowa <= n; ++rowa){
    for(int rowb = rowa; rowb <= n; rowb++){
      int rowSum = asum[rowb] - asum[rowa - 1];
      int rowLen = rowb - rowa + 1;
      if (alensum[rowLen] == 0) alensum[rowLen] = rowSum;
      else alensum[rowLen] = min(alensum[rowLen], rowSum);
    }
  }

  for(int cola = 1; cola <= m; cola++){
    for(int colb = cola; colb <= m; colb++){
      int colSum = bsum[colb] - bsum[cola - 1];
      int colLen = colb - cola + 1;
      if (blensum[colLen] == 0) blensum[colLen] = colSum;
      else blensum[colLen] = min(blensum[colLen], colSum);
    }
  }

  map<int, int> colSumLen;
  for (int i = 1; i <= m; ++i){
    if (blensum[i] != 0){
      colSumLen[blensum[i]] = i;
    }
  }

  int ret = 0;

  for (int len = 1; len <= n; ++len){
    int rowSum = alensum[len];
    if (rowSum == 0) continue;

    if (len * m < ret) break;

    int remain = x / rowSum;
    auto it = colSumLen.upper_bound(remain);
    if (it != colSumLen.begin()){
      it--;
      ret = max(ret, len * it->second);
    }
  }

  printf("%d", ret);
}