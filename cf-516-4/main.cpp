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

int n, m;
int r, c;
int x, y;
char laby[2006][2006];
int maxLeft[2006][2006];
int maxRight[2006][2006];
bool inQueue [2006][2006];
bool canVisit[2006][2006];
vector<pii> stk;

void flush(int row, int col){
  for (int i = 0; row - i >= 1 && laby[row - i][col] == '.'; ++i){
    maxLeft[row - i][col] = maxLeft[row][col];
    maxRight[row - i][col] = maxRight[row][col];
    canVisit[row - i][col] = true;
    // printf("flush up %d %d\n", row - i, col);
    if (!inQueue[row - i][col]){
      stk.push_back(mp(row - i, col));
      inQueue[row - i][col] = true;
    }
  }
  for (int i = 1; row + i <= n && laby[row + i][col] == '.'; ++i){
    maxLeft[row + i][col] = maxLeft[row][col];
    maxRight[row + i][col] = maxRight[row][col];
    canVisit[row + i][col] = true;
    // printf("flush down %d %d\n", row + i, col);
    if (!inQueue[row + i][col]){
      stk.push_back(mp(row + i, col));
      inQueue[row + i][col] = true;
    }
  }
}

int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
  for (int row = 1; row <= n; ++row){
    char line[2006];
    scanf("%s", line);

    for (int col = 1; col <=m; ++col){
      laby[row][col] = line[col - 1];
    }
  }

  maxLeft[r][c] = x;
  maxRight[r][c] = y;
  flush(r, c);

  while (!stk.empty()){
    int row = stk.back().first;
    int col = stk.back().second;
    stk.pop_back();

    inQueue[row][col] = false;

    // printf("check %d %d\n", row, col);

    int leftCol = col - 1;
    if (leftCol >= 1 && maxLeft[row][col] >= 1 && laby[row][leftCol] != '*'){
      if (!canVisit[row][leftCol] || maxLeft[row][leftCol] < maxLeft[row][col] - 1){
        maxLeft[row][leftCol] = maxLeft[row][col] - 1;
        maxRight[row][leftCol] = maxRight[row][col];
        // printf("left %d %d, %d\n", row, leftCol, maxLeft[row][leftCol]);
        flush(row, leftCol);
      }
    }

    int rightCol = col + 1;
    if (rightCol <= m && maxRight[row][col] >= 1 && laby[row][rightCol] != '*'){
      if (!canVisit[row][rightCol] || maxRight[row][rightCol] < maxRight[row][col] - 1){
        maxRight[row][rightCol] = maxRight[row][col] - 1;
        maxLeft[row][rightCol] = maxLeft[row][col];
        // printf("right %d %d, %d\n", row, rightCol, maxRight[row][rightCol]);
        flush(row, rightCol);
      }
    }
  }

  int ret = 0;
  for (int row = 1; row <= n; ++row){
    for (int col = 1; col <=m; ++col){
      ret += canVisit[row][col] ? 1 : 0;
    }
  }

  printf("%d", ret);
}