#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

unsigned N;

int main() {
	scanf("%d", &N);

	int isLastOne = false;
	int count = 0;
	int result = 0;
	while (N > 0) {
		int cur = N & 0x1;

		if (cur == 0x1){
			isLastOne = true;
			count++;
			N >>= 1;
		}
		else {
			if (isLastOne) {
				result++;
				if (count >= 2){
					N |= 0x1;				
				}
				else {
					N >>= 1;
				}
			}
			else {
				N >>= 1;
			}

			isLastOne = false;
			count = 0;
		}
	}
	
	if (isLastOne) {
		result += min(count, 2);
	}

	printf("%d", result);
}