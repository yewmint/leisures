#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
  return static_cast<ll>(val);
}

int n;

int main() {
  scanf("%d", &n);
  vector<int> nums(n);
  for (int i = 0; i < n; ++i){
    int num;
    scanf("%d", &num);
    nums[i] = num & 0xff;
  }

  int i = 0;
  bool qualified = true;
  while (i < nums.size()){
    int root = nums[i];
    
    int head = (root >> 7) & 0x1;
    if (head == 0){
      i++;
      continue;
    }
    
    int len = 0;
    while ((root >> 7) & 0x1 == 1){
      root <<= 1;
      len++;
      if (len > 4) break;
    }
    if (len < 2 || len > 4 || i + len > nums.size()){
      qualified = false;
      break;
    }

    for (int j = 1; j < len; ++j){
      int num = nums[i + j];
      int eight = (num >> 7) & 0x1;
      int seven = (num >> 6) & 0x1;
      if (eight != 1 || seven != 0){
        qualified = false;
        break;
      }
    }
    if (!qualified) break;

    i += len;
  }

  if (qualified){
    printf("1\n");
  }
  else {
    printf("0\n");
  }
}