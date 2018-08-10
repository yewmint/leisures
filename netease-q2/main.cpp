#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

int N;

int main() {
	scanf("%d", &N);
	while (N--){
		string password;
		cin >> password;

		// 1
		if (password.size() < 8){
			printf("no\n");
			continue;
		}

		// 2
		bool hasUpper = false;
		bool hasLower = false;
		bool hasNumber = false;
		bool hasSymbol = false;
		string symbols = "!@#$%^&*()_-=+[]{},.<>/?";
		for (char ch : password){
			if (ch >= 'A' && ch <= 'Z') hasUpper = true;
			else if (ch >= 'a' && ch <= 'z') hasLower = true;
			else if (ch >= '0' && ch <= '9') hasNumber = true;
			else if (symbols.find(ch) != string::npos) hasSymbol = true;
		}
		if (!hasUpper || !hasLower || !hasNumber || !hasSymbol){
			printf("no\n");
			continue;
		}

		// 3
		vector<int> seq;
		bool hasSeq = false;
		for (char ch : password){
			if (ch < '0' || ch > '9') {
				seq.clear();
				continue;
			}

			seq.push_back(ch - '0');
			if (seq.size() >= 3){
				if (seq[2] - seq[1] == seq[1] - seq[0]){
					hasSeq = true;
					break;
				}
				seq.erase(seq.begin());
			}
		}
		if (hasSeq){
			printf("no\n");
			continue;
		}

		// 4
		vector<int> chSeq;
		bool hasChSeq = false;
		for (char ch : password){
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
				seq.push_back(ch - 'A');

				if (seq.size() >= 3){
					if (seq[2] - seq[1] == 1 && seq[1] - seq[0] == 1){
						hasChSeq = true;
						break;
					}
					seq.erase(seq.begin());
				}
			}
			else {
				chSeq.clear();
			}
		}
		if (hasChSeq){
			printf("no\n");
			continue;
		}

		// 5
		vector<string> weaks = { 
			"password",
			"admin",
			"qwerty",
			"hello",
			"hello",
			"iloveyou",
			"112233"
		};
		bool hasWeak = false;
		for (string weak : weaks){
			if (password.find(weak) != string::npos){
				hasWeak = true;
				break;
			}
		}
		if (hasWeak){
			printf("no\n");
			continue;
		}

		printf("yes\n");
	}
}