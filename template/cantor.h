int factorial(int x) {
	int ret = 1;
	for (int i = 2; i <= x; ++i) {
		ret *= i;
	}
	return ret;
}

int cantor(vector<int> & nums) {
	int len = nums.size();
	int x = 0;
	for (int i = 0; i < len; ++i) {
		int tp = 0;
		for (int j = i + 1; j < len; ++j) {
			if (nums[j] < nums[i]) {
				tp++;
			}
		}
		x += tp * factorial(len - i - 1);
	}
	return x;
}

vector<int> uncantor(int len, int order) {
	vector<int> a(len);
	vector<int> nums(len);
	vector<bool> used(len);

	for (int i = 0; i < len; ++i) {
		int fact = factorial(len - i - 1);
		a[i] = order / fact;
		order = order % fact;
		int cnt = 0;

		for (int j = 0; j < len; ++j) {
			if (!used[j]) {
				cnt++;
				if (cnt == a[i] + 1) {
					nums[i] = j;
					used[j] = true;
					break;
				}
			}
		}
	}

	return nums;
}