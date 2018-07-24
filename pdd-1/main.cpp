#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	int N;
	scanf("%d", &N);

	int q = 4;
	while (q < N) {
		N -= q;
		q += q;
	}

	char names[4][10] = { "Alice", "Bob", "Cathy", "Dave" };
	printf("%s", names[int(ceil(double(N) / (q / 4))) - 1]);
}