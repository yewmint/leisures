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

char str[100006];

int main() {
  scanf("%s", str);

  int ret = 0;
  for (int i = 1; str[i - 1] != '\0' && str[i] != '\0'; i++){
    if (str[i] == str[i - 1]) {
      ret++;
      i++;
    }
  }

  printf("%d", ret);
}