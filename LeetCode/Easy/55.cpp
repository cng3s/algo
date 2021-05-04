// 执行用时：8 ms, 在所有 C++ 提交中击败了96.80% 的用户
// 内存消耗：20.3 MB, 在所有 C++ 提交中击败了74.94% 的用户

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
    int getTreeHeight(TreeNode* root) {
        int ans = 0;
        if (root) {
            int left = getTreeHeight(root->left);
            if (left == -1) { return -1; }
            int right = getTreeHeight(root->right);
            if (right == -1 || abs(left - right) > 1) { return -1; }
            ans = max(left, right) + 1;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) { return true; }
        int left = getTreeHeight(root->left), right = 0;
        if (left != -1) {
            right = getTreeHeight(root->right);
        }
        return left == -1 || right == -1 ? false : (abs(left - right) > 1 ? false : true);
    }
};