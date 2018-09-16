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

int findKth(int *a, int alen, int *b, int blen, int k){
  if (alen > blen) return findKth(b, blen, a, alen, k);
  if (alen == 0) return b[k - 1];
  if (k == 1) return min(a[0], b[0]);

  int amid = min(alen, k / 2);
  int bmid = k - amid;
  if (a[amid - 1] > b[bmid - 1]) {
    return findKth(a, alen, b + bmid, blen - bmid, k - bmid);
  }
  else if (a[amid - 1] < b[bmid - 1]) {
    return findKth(a + amid, alen - amid, b, blen, k - amid);
  }
  else {
    return a[amid - 1];
  }
}

int main() {
  scanf("%d%d", &n, &m);

  int *a = new int[n];
  int *b = new int[m];
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

  int total = n + m;
  double ret = -1;

  if (total & 0x1 == 1){
    ret = findKth(a, n, b, m, total / 2 + 1);
  }
  else {
    double kaval = findKth(a, n, b, m, total / 2);
    double kbval = findKth(a, n, b, m, total / 2 + 1);
    ret = (kaval + kbval) / 2.0;
  }

  printf("%lf", ret);

  delete a;
  delete b;
}