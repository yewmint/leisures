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
  ll last[128];
  for (int i = 0; i < 128; i++) last[i] = -1;

  int i = -1;
  char ch;
  ll len = 0, ret = 0;
  while (scanf("%c", &ch) != EOF){
    i++;
    if (ch == '\r' || ch == '\n') break;

    if (last[ch] == -1){
      last[ch] = i;
      len++;
    }
    else {
      int pos = last[ch];
      for (int j = 0; j < 128; ++j){
        if (last[j] >= 0 && last[j] <= pos){
          last[j] = -1;
          len--;
        }
      }
      last[ch] = i;
      len++;
    }

    ret = max(ret, len);
  }

  printf("%lld", ret);
}