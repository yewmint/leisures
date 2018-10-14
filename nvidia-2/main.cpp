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

int n, x0, yy0;

int merge(vector<int> &nums, int begin, int end){
  if (begin >= end) return 0;

  int inverse = 0;
  int mid = begin + (end - begin) / 2;
  inverse += merge(nums, begin, mid);
  inverse += merge(nums, mid + 1, end);

  vector<int> tmpa(nums.begin() + begin, nums.begin() + mid + 1);
  vector<int> tmpb(nums.begin() + mid + 1, nums.begin() + end + 1);
  int aptr = 0, bptr = 0, ptr = begin;

  while (aptr < tmpa.size() && bptr < tmpb.size()){
    if (tmpa[aptr] <= tmpb[bptr]){
      nums[ptr] = tmpa[aptr];
      aptr++;
      ptr++;
    }
    else {
      nums[ptr] = tmpb[bptr];
      bptr++;
      ptr++;

      inverse += (bptr + mid + 1) - ptr;
    }
  }

  while (aptr < tmpa.size()){
    nums[ptr] = tmpa[aptr];
    aptr++;
    ptr++;
  }

  while (bptr < tmpb.size()){
    nums[ptr] = tmpb[bptr];
    bptr++;
    ptr++;
  }

  return inverse;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> nums(n);

  for (int i = 0; i < n; ++i){
    scanf("%d", &nums[i]);
  }

  printf("%d", merge(nums, 0, nums.size() - 1));
}