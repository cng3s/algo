// 执行用时：4 ms, 在所有 C++ 提交中击败了73.04% 的用户
// 内存消耗：11.6 MB, 在所有 C++ 提交中击败了99.06% 的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root) { return {}; }
        queue<TreeNode*> q;
        vector<int> ans;

        q.emplace(root);
        while (!q.empty()) {
            TreeNode* x = q.front();
            q.pop();
            ans.emplace_back(x->val);
            if (x->left) { q.emplace(x->left); }
            if (x->right) { q.emplace(x->right); }
        }
        return ans;
    }
};