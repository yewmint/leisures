#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

string nearestPalindromic(string n) {
	const int LEN = n.size();

	set<ll> nums;
	
	nums.insert(static_cast<ll>(pow(10, LEN - 1)) + 1);
	nums.insert(static_cast<ll>(pow(10, LEN)) - 1);
	nums.insert(static_cast<ll>(pow(10, LEN)) + 1);
	nums.insert(static_cast<ll>(pow(10, LEN - 1)) - 1);

	ll prefix = stoll(n.substr(0, (LEN + 1) / 2));
	for (int i = -1; i <= 1; ++i){
		string fixedPrefix = to_string(prefix + i);
		string splice(fixedPrefix.rbegin() + (LEN & 0x1), fixedPrefix.rend());
		ll num = stoll(fixedPrefix + splice);
		nums.insert(num);
	}

	ll target = stoll(n);
	nums.erase(target);

	ll closest = LLONG_MAX;
	for (ll num : nums){
		if (abs(closest - target) > abs(num - target)){
			closest = num;
		}
		else if (abs(closest - target) == abs(num - target)){
			closest = min(closest, num);
		}
	}

	return to_string(closest);
}

int main() {
	string arg0 = "10";
	cout << nearestPalindromic(arg0) << endl;
	cout << "finished" << endl;
	cin.get();
}