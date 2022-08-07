// 执行用时：4 ms, 在所有 C++ 提交中击败了46.56% 的用户
// 内存消耗：8.6 MB, 在所有 C++ 提交中击败了44.66% 的用户
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> q;
        vector<int> ret;

        if (nullptr != root) { q.emplace(root); }
        while (!q.empty()) {
            TreeNode* cur = q.top();
            ret.emplace_back(cur->val);
            q.pop();
            if (nullptr != cur->right) { q.emplace(cur->right); }
            if (nullptr != cur->left) { q.emplace(cur->left); }
        }

        return ret;
    }
};