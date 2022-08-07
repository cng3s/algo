// 执行用时：16 ms, 在所有 C++ 提交中击败了16.94% 的用户
// 内存消耗：13.1 MB, 在所有 C++ 提交中击败了12.49% 的用户
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
    void flatten(TreeNode* root) {
        if (nullptr == root) { return; }

        stack<TreeNode*> s;
        s.emplace(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (nullptr != cur->right) { s.emplace(cur->right); }
            if (nullptr != cur->left) { s.emplace(cur->left); }
            cur->left = nullptr;
            if (s.size() >= 1) { cur->right = s.top(); }
        }
    }
};