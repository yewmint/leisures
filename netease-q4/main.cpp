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
	TrieNode *nodes[10] = { 0 };
	char *location = NULL;
};

int main() {
	scanf("%d", &T);
	while (T--){
		TrieNode *root = new TrieNode;

		scanf("%d", &N);
		while (N--){
			char number[12], location[31];
			scanf("%s%s", number, location);
			
			TrieNode *cur = root;
			for (int i = 0; number[i] != '\0'; ++i){
				char ch = number[i];

				if (ch != 'x'){
					if (cur->nodes[ch - '0'] == NULL){
						cur->nodes[ch - '0'] = new TrieNode;
					}
					cur = cur->nodes[ch - '0'];
				}
				else {
					cur->location = new char[31];
					strcpy(cur->location, location);
					break;
				}

				if (number[i + 1] == '\0'){
					cur->location = new char[31];
					strcpy(cur->location, location);
				}
			}
		}

		scanf("%d", &M);
		while (M--){
			char number[12];
			scanf("%s", number);

			TrieNode *cur = root;
			bool found = true;
			for (int i = 0; number[i] != '\0'; ++i){
				char ch = number[i];

				if (cur->location != NULL){
					printf("%s\n", cur->location);
					break;
				}
				else if (cur->nodes[ch - '0'] != NULL){
					cur = cur->nodes[ch - '0'];
				}
				else {
					found = false;
					break;
				}

				if (cur->location != NULL){
					printf("%s\n", cur->location);
					break;
				}
			}

			if (!found){
					printf("unknown\n");
			}
		}
	}
}