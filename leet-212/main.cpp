#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

#define mp make_pair

struct TrieNode {
	bool isWord = false;
	int word = -1;
	TrieNode *children[26] = { NULL };
};

TrieNode* buildTrie(vector<string> &words) {
	TrieNode *root = new TrieNode;

	for (int i = 0; i < words.size(); ++i) {
		string &word = words[i];
		TrieNode* cur = root;
		for (auto ch : word) {
			int idx = ch - 'a';
			if (!cur->children[idx]) {
				cur->children[idx] = new TrieNode;
			}
			cur = cur->children[idx];
		}
		cur->isWord = true;
		cur->word = i;
	}

	return root;
}

const int dirs[5] = { -1, 0, 1, 0, -1 };
int ROWS;
int COLS;

void traverse(
	vector<vector<char>>& board,
	vector<string>& words,
	vector<vector<bool>>& visited,
	set<string>& ans,
	int row,
	int col,
	TrieNode *parent
) {
	if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
		return;
	}

	if (visited[row][col]) {
		return;
	}

	TrieNode *node = parent->children[board[row][col] - 'a'];
	if (!node) {
		return;
	}

	if (node->isWord) {
		ans.insert(words[node->word]);
	}

	visited[row][col] = true;

	for (int i = 0; i < 4; ++i) {
		int r = row + dirs[i];
		int c = col + dirs[i + 1];
		traverse(board, words, visited, ans, r, c, node);
	}

	visited[row][col] = false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	ROWS = board.size();
	COLS = board[0].size();
	TrieNode *root = buildTrie(words);
	set<string> ans;
	vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

	for (int r = 0; r < board.size(); ++r) {
		for (int c = 0; c < board[0].size(); ++c) {
			traverse(board, words, visited, ans, r, c, root);
		}
	}

	vector<string> ret(ans.begin(), ans.end());
	return ret;
}

int main() {
	vector<vector<char>> arg0 = {
		{'o', 'a', 'a', 'n'},
		{'e', 't', 'a', 'e'},
		{'i', 'h', 'k', 'r'},
		{'i', 'f', 'l', 'v'}
	};

	vector<string> arg1 = {
		"oath","pea","eat","rain"
	};

	auto ans = findWords(arg0, arg1);
	for (auto line : ans) {
		cout << line << endl;
	}
	
	cin.get();
}