#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int traverse(string &str, int pos, int seg){
  if (pos == str.size() && seg == 4) return 1;
  if (str.size() - pos < (4 - seg) * 1) return 0;
  if (str.size() - pos > (4 - seg) * 3) return 0;

  int ret = 0;
  ret += traverse(str, pos + 1, seg + 1);

  if (str[pos] != '0' && pos + 1 < str.size()){
    ret += traverse(str, pos + 2, seg + 1);
  }

  if (pos + 2 < str.size()){
    if (str[pos] == '1'){
      ret += traverse(str, pos + 3, seg + 1);
    }
    else if (str[pos] == '2'){
      if (str[pos + 1] <= '4'){
        ret += traverse(str, pos + 3, seg + 1);
      }
      else if (str[pos + 1] == '5' && str[pos + 2] <= '5'){
        ret += traverse(str, pos + 3, seg + 1);
      }
    }
  }

  return ret;
}

int main() {
  string str;
  cin >> str;
  printf("%d", traverse(str, 0, 0));
}