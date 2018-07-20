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

int findKthNumber(int m, int n, int k) {
	int low = 1, high = m * n + 1;

	while (low < high){
		int mid = (low + high) / 2;
		int index = 0;
		for (int i = 1; i <= m; ++i){
			index += min(n, mid / i);
		}
		if (index >= k) high = mid;
		else low = mid + 1;
	}

	return high;
}

int main() {
	cout << findKthNumber(3, 3, 5) << endl;
	cout << findKthNumber(2, 3, 6) << endl;

	cout << "finished" << endl;
	cin.get();
}