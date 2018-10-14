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

multiset<int> nums;
int N, M;

int main() {
  scanf("%d%d", &N, &M);
  while (N--){
    int num;
    scanf("%d", &num);
    nums.insert(num);
  }

  ll sum = 0;
  for (auto it = nums.begin(); it != nums.end() && next(it) != nums.end(); ++it){
    sum += scll(pow(*it - *next(it), 2));
  }

  while (M--){
    char opt[10];
    int num;
    scanf("%s%d", opt, &num);

    if (strcmp(opt, "INS") == 0){
      auto first = nums.lower_bound(num);
      auto last = nums.upper_bound(num);

      if (first == last){
        if (first != nums.begin()){
          sum += scll(pow(*prev(first) - num, 2));
        }
        if (first != nums.end()){
          sum += scll(pow(*first - num, 2));
        }

        if (first != nums.begin() && first !=nums.end()){
          sum -= scll(pow(*first - *prev(first), 2));
        }
      }

      nums.insert(num);
    }
    else {
      auto first = nums.lower_bound(num);
      auto last = nums.upper_bound(num);

      if (first != last){
        if (first != nums.begin()){
          sum -= scll(pow(num - *prev(first), 2));
        }
        if (last != nums.end()){
          sum -= scll(pow(*last - num, 2));
        }

        if (first != nums.begin() && last != nums.end()){
          sum += scll(pow(*prev(first) - *last, 2));
        }
      }

      nums.erase(num);
    }

    printf("%lld\n", sum);
  }
}