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
list<pair<int, int>> cacheList;
unordered_map<int, list<pair<int, int>>::iterator> dict;

int main() {
  scanf("%d", &n);

  char op[10];
  int key, value;

  while (scanf("%s", op) != EOF) {
    if (op[0] == 'p'){
      scanf("%d%d", &key, &value);

      if (dict.count(key) > 0){
        dict[key]->second = value;
      }
      else {      
        cacheList.push_back(mp(key, value));
        dict[key] = prev(cacheList.end());

        if (dict.size() > n){
          int delKey = cacheList.front().first;
          cacheList.erase(cacheList.begin());
          dict.erase(delKey);
        }
      }
    }
    else if (op[0] == 'g'){
      scanf("%d", &key);

      if (dict.count(key) > 0){
        value = dict[key]->second;
        printf("%d\n", value);

        cacheList.erase(dict[key]);
        cacheList.push_back(mp(key, value));
        dict[key] = prev(cacheList.end());
      }
      else {
        printf("-1\n");
      }
    }
  }
}