#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int main() {
  int n, A;
  scanf("%d%d", &n, &A);
  set<int> rets;

  while (n--){
    int id, in, out;
    scanf("%d%d%d", &id, &in, &out);

    if (A >= in && A <= out){
      rets.insert(id);
    }
  }

  for (auto id : rets){
    printf("%d\n", id);
  }

  if (rets.empty()){
    printf("null");
  }
}