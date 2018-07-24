#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	multiset<int> goods;
	int ret = 0;

	int hundCnt = 0;
	int num;
	while (cin >> num){
		if (num == 100) hundCnt++;
		else goods.insert(num);
	}

	ret += hundCnt / 3;
	hundCnt %= 3;
	while (hundCnt--) goods.insert(100);

	while (!goods.empty()){
		ret++;

		int a = *goods.rbegin();
		goods.erase(prev(goods.end()));

		if (goods.empty()) break;

		auto pb = goods.upper_bound(300 - a);
		if (pb != goods.begin()){
			pb--;
			goods.erase(pb);
		}
	}

	printf("%d", ret);
}