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

int t;

bool isMatch(vector<int> & perm, vector<pii> & cards){
  return 
    (cards[perm[1]].first == cards[perm[3]].second) &&
    (cards[perm[0]].first == cards[perm[1]].second && cards[perm[0]].first == cards[perm[4]].first) && 
    (cards[perm[0]].second == cards[perm[2]].first && cards[perm[0]].second == cards[perm[4]].second) &&
    (cards[perm[2]].second == cards[perm[5]].first);
}

int main() {
  scanf("%d", &t);
  while (t--){
    vector<pair<int, int>> cards(6);
    for (int i = 0; i < 6; ++i){
      scanf("%d%d", &cards[i].first, &cards[i].second);
    }

    vector<int> permutaion = { 0, 1, 2 ,3 ,4 ,5 };
    bool found = false;

    while (true){    
      for (int rev1 = 0; rev1 <= 1; ++rev1){
        swapPair(cards[0]);
        for (int rev2 = 0; rev2 <= 1; ++rev2){
          swapPair(cards[1]);
          for (int rev3 = 0; rev3 <= 1; ++rev3){
            swapPair(cards[2]);
            for (int rev4 = 0; rev4 <= 1; ++rev4){
              swapPair(cards[3]);
              for (int rev5 = 0; rev5 <= 1; ++rev5){
                swapPair(cards[4]);
                for (int rev6 = 0; rev6 <= 1; ++rev6){
                  swapPair(cards[5]);

                  if (isMatch(permutaion, cards)){
                    found = true;
                    break;
                  }
                }
              }
            }
          }
        }
      }

      if (!next_permutation(permutaion.begin(), permutaion.end())){
        break;
      }
    }

    printf("%s\n", found ? "YES" : "NO");
  }
}