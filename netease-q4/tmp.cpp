#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

int T, N, M;

struct TrieNode{
	bool hasLocation = false;
	TrieNode *nodes[10] = { 0 };
	string *location = NULL;
};

int main() {
	scanf("%d", &T);
	while (T--){
		TrieNode *root = new TrieNode;

		scanf("%d", &N);
		while (N--){
			string number, location;
			cin >> number >> location;
			
			TrieNode *cur = root;
			for (int i = 0; i < number.size(); ++i){
				char ch = number[i];

				if (ch != 'x'){
					if (cur->nodes[ch - '0'] == NULL){
						cur->nodes[ch - '0'] = new TrieNode;
					}
					cur = cur->nodes[ch - '0'];
				}
				else {
					cur->hasLocation = true;
					cur->location = new string(location);
					break;
				}

				if (i + 1 == number.size()){
					cur->hasLocation = true;
					cur->location = new string(location);
				}
			}
		}

		scanf("%d", &M);
		while (M--){
			string number;
			cin >> number;

			TrieNode *cur = root;
			bool found = true;
			for (char ch : number){
				if (cur->hasLocation){
					cout << *cur->location << endl;
					break;
				}
				else if (cur->nodes[ch - '0'] != NULL){
					cur = cur->nodes[ch - '0'];
				}
				else {
					found = false;
					break;
				}

				if (cur->hasLocation){
					cout << *cur->location << endl;
					break;
				}
			}

			if (!found){
				cout << "unknown" << endl;
			}
		}
	}
}