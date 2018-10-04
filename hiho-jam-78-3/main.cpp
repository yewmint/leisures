#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

void swapPair(pii & iiPair){
  swap(iiPair.first, iiPair.second);
}

int n;

int main() {
  scanf("%d", &n);

  vector<int> factors(10, 0);
  for (int curFactor = 9; curFactor >= 2; --curFactor){
    while (n % curFactor == 0){
      n /= curFactor;
      factors[curFactor]++;
    }
  }

  if (n > 1){
    printf("-1");
    return 0;
  }

  string xStr;
  for (int i = 2; i <= 9; ++i){
    while (factors[i] > 0){
      factors[i]--;
      xStr += to_string(i);
    }
  }

  if (xStr.empty()){
    xStr += "1";
  }

  printf("%s", xStr.c_str());
}