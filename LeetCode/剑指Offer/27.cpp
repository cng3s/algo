// 执行用时：4 ms, 在所有 C++ 提交中击败了48.87% 的用户
// 内存消耗：8.9 MB, 在所有 C++ 提交中击败了53.64% 的用户

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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) { return nullptr; }

        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) { q.emplace(node->left); }
            if (node->right) { q.emplace(node->right); }
            swap(node->left, node->right);
        }

        return root;
    }
};