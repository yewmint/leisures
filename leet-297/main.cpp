#include <iostream>
#include <string>
#include <sstream>
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define mp make_pair

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string serial;
		if (!root) return serial;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			auto node = q.front(); q.pop();
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);

			serial += to_string(node->val);
			serial += node->left ? "#" : "*";
			serial += node->right ? "#" : "*";
		}

		return serial;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) return nullptr;

		stringstream serial(data);
		queue<pair<TreeNode*, bool>> q;

		int val;
		serial >> val;
		TreeNode *root = new TreeNode(val);

		if (serial.get() == '#') q.push(mp(root, true));
		if (serial.get() == '#') q.push(mp(root, false));

		while (!q.empty()) {
			auto pa = q.front(); q.pop();
			auto parent = pa.first;
			auto isLeft = pa.second;

			serial >> val;
			TreeNode *node = new TreeNode(val);

			if (isLeft) parent->left = node;
			else parent->right = node;

			if (serial.get() == '#') q.push(mp(node, true));
			if (serial.get() == '#') q.push(mp(node, false));
		}

		return root;
	}
};

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	Codec codec;
	cout << codec.serialize(root) << endl;
	cout << codec.serialize(codec.deserialize(codec.serialize(root))) << endl;

	cin.get();
}