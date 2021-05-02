// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：18.4 MB, 在所有 C++ 提交中击败了55.13% 的用户

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) { return 0; }
        queue<TreeNode*> q1, q2;
        queue<TreeNode*> *cur = &q1,
                         *next = &q2;
        int ans = 0;
        cur->emplace(root);

        while (!cur->empty()) {
            while (!cur->empty()) {
                TreeNode* node = cur->front();
                cur->pop();
                if (node->left) { next->emplace(node->left); }
                if (node->right) { next->emplace(node->right); }
            }
            swap(cur, next);
            ++ans;
        }
        return ans;
    }
};