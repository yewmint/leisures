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

int n;
char str[100006];
int counts[26];

bool hasLeft(){
  for (int i = 0; i < 26; ++i){
    if (counts[i] > 0) return true;
  }
  return false;
}

int maxIndex(){
  int idx = 0;
  for (int i = 1; i < 26; ++i){
    if (counts[i] > counts[idx]) idx = i;
  }
  return idx;
}

int main() {
  scanf("%d", &n);
  scanf("%s", str);
  for (int i = 0; i < n; ++i){
    counts[str[i] - 'a']++;
  }

  // string ret;
  // vector<char> stk;
  // vector<string> remainStk;
  // while (hasLeft()){
  //   int idx = maxIndex();
  
  //   stk.push_back('a' + idx);
  //   counts[idx]--;

  //   string remain;

  //   for (int i = 0; i < 26; ++i){
  //     if (counts[i] & 0x1 == 1){
  //       remain += string(1, i + 'a');
  //     }

  //     counts[i] /= 2;
  //   }

  //   remainStk.push_back(remain);
  // }

  // while (!stk.empty()){
  //   ret = ret + string(1, stk.back()) + string(ret.rbegin(), ret.rend());
  //   stk.pop_back();
    
  //   ret += remainStk.back();
  //   remainStk.pop_back();
  // }

  string ret;
  for (int i = 0; i < 26; ++i){
    ret += string(counts[i], i + 'a');
  }

  printf("%s", ret.c_str());
}