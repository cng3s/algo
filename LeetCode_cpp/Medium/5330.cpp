/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	typedef unsigned long long ull;
	vector<ull> sums;
	static const ull mod = 1e9 + 7;

	int maxProduct(TreeNode* root) {
		ull res = 0;
		post_order(root);
		for (int i = 0; i < sums.size() - 1; ++i)
			res = max(res, sums[i] * (sums.back() - sums[i]));
		return int(res % mod);
	}

	ull post_order(TreeNode* root) {
		if (root == nullptr)
			return 0;
		ull res = root->val + post_order(root->left) + post_order(root->right);
		sums.push_back(res);
		return res;
	}
};


// 层序遍历创建树
struct TreeNode* create_tree(vector<int>& lev)
{
	int idx = 0;
	struct TreeNode *root = new TreeNode(lev[0]);
	queue<struct TreeNode*> q;
	q.push(root);
	
	while (!q.empty()) {
		struct TreeNode *cur = q.front();
		q.pop();
		if (++idx < lev.size() && lev[idx] != -1) {
			cur->left = new TreeNode(lev[idx]);
			q.push(cur->left);
		}
		if (++idx < lev.size() && lev[idx] != -1) {
			cur->right = new TreeNode(lev[idx]);
			q.push(cur->right);
		}
	}
	return root;
}

int main()
{
	vector<int> lev = { 1,2,3,4,5,6 };
	struct TreeNode *tree = create_tree(lev);
	Solution sol;
	int res = sol.maxProduct(tree);
	cout << res;

	return 0;
}