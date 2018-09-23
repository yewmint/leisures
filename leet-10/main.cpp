#include <bits/stdc++.h>

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

bool isMatch(string s, string p) {
  vector<vector<bool>> match(p.size() + 1, vector<bool>(s.size() + 1, false));
  match[0][0] = true;

  for (int i = 2; i <= p.size(); i += 2){
    match[i][0] = match[i - 2][0] && p[i - 1] == '*';
  }

  for (int i = 1; i <= p.size(); ++i){
    for (int j = 1; j <= s.size(); ++j){
      if (p[i - 1] == '.'){
        match[i][j] = match[i - 1][j - 1];
      }
      else if (p[i - 1] == '*'){
        match[i][j] = 
          (match[i - 2][j]) ||
          (match[i - 1][j]) ||
          (p[i - 2] == '.' && match[i][j - 1]) ||
          (match[i][j - 1] && j >= 2 && s[j - 1] == p[i - 2]);
      }
      else {
        match[i][j] = p[i - 1] == s[j - 1] && match[i - 1][j - 1];
      }
    }
  }

  return match[p.size()][s.size()];
}

int main() {
	cout << boolalpha;

  cout << isMatch("s", "s") << endl;
  cout << isMatch("a", "aa") << endl;
  cout << isMatch("aa", "a*") << endl;
  cout << isMatch("ab", ".*") << endl;
  cout << isMatch("aab", "c*a*b") << endl;
  cout << isMatch("mississippi", "mis*is*p*.") << endl;

	cin.get();
}