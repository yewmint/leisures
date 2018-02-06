#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

enum FLAG {
	DEBUT, LEFT, RIGHT
};

vector<int> postorderTraversal(TreeNode* root) {
	if (!root) {
		return vector<int>();
	}

	vector<int> ans;
	unordered_map<TreeNode*, FLAG> flags;
	vector<TreeNode*> stack;

	stack.push_back(root);
	flags[root] = DEBUT;

	while (!stack.empty()) {
		auto node = stack.back(); 
		stack.pop_back();

		if (flags[node] == DEBUT) {
			stack.push_back(node);
			flags[node] = LEFT;

			if (node->left) {
				stack.push_back(node->left);
				flags[node->left] = DEBUT;
			}
		}
		else if (flags[node] == LEFT) {
			stack.push_back(node);
			flags[node] = RIGHT;

			if (node->right) {
				stack.push_back(node->right);
				flags[node->right] = DEBUT;
			}
		}
		else {
			ans.push_back(node->val);
		}
	}

	return ans;
}

int main() {
	auto root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	auto ans = postorderTraversal(root);
	for (auto line : ans) {
		cout << line << endl;
	}

	cin.get();
}