#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int N, A[100006];

int main() {
	scanf("%d", &N);
	if (N <= 1){
		printf("0");
		return 0;
	}

	for (int i = 0; i < N; ++i){
		scanf("%d", A + i);
	}

	int lhsIndex = 0;
	int ascTurn = A[N - 1];
	for (int i = N - 1; i >= 1; --i){
		if (A[i - 1] > A[i]){
			ascTurn = min(ascTurn, A[i]);
		} 
	}
	for (int i = 0; i < N; ++i){
		if (A[i] > ascTurn){
			lhsIndex = i;
			break;
		}
	}

	int rhsIndex = N - 1;
	int desTurn = 0;
	for (int i = 0; i < N - 1; ++i){
		if (A[i + 1] < A[i]){
			desTurn = max(desTurn, A[i]);
		} 
	}
	for (int i = N - 1; i >= 0; --i){
		if (A[i] < desTurn){
			rhsIndex = i;
			break;
		}
	}

	printf("%d", rhsIndex - lhsIndex + 1);
	return 0;
}