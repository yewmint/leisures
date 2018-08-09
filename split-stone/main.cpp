#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

#define MAXN 100006
int N, A[MAXN];

int main() {
	vector<int> nums;
	int tnum;
	while (scanf("%d,", &tnum) != EOF){
		nums.push_back(tnum);
	}

	int total = accumulate(nums.begin(), nums.end(), 0);
	int half = total / 2;

	set<int> cloest;
	int retA = 0;
	for (int num : nums){
		int remain = half - num;
		if (remain == 0){
			retA = num;
			break;
		}
		else if (remain > 0){
			auto nt = cloest.upper_bound(remain);
			if (nt != cloest.begin()){
				nt--;

				int cur = *nt + num;
				retA = max(retA, cur);
				if (cur == half) break;

				cloest.insert(cur);
			}
			else {
				cloest.insert(num);
			}
		}
	}

	int a = max(retA, total - retA);
	int b = total - a;
	printf("%d,%d", a, b);
}