#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int N, M;
char rates[56][56];

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; ++i){
		scanf("%s", rates[i]);
	}

	for (int cur = 0; cur < N; ++cur){
		int beat = 0;

		for (int riv = 0; riv < N; ++riv){
			if (riv == cur) continue;

			int diff = 0;
			for (int i = 0; i < M; ++i){
				if (rates[i][cur] < rates[i][riv]) diff++;
				else if (rates[i][cur] > rates[i][riv]) diff--;
			}

			if (diff > 0) beat++;
		}

		if (beat >= N - 1){
			printf("%d", cur);
			return 0;
		}
	}

	printf("-1");
}