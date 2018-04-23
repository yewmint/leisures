int N, M;
ll BIT2[1006][1006];

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int y, int val) {
	for (int i = x; i <= N; i += lowbit(i)) {
		for (int j = y; j <= N; j += lowbit(j)) {
			BIT2[i][j] += val;
		}
	}
}

ll sum(int x, int y) {
	ll ret = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		for (int j = y; j > 0; j -= lowbit(j)) {
			ret += BIT2[i][j];
		}
	}
	return ret;
}