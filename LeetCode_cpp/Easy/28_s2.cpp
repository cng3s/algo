// 执行用时：8 ms, 在所有 C++ 提交中击败了49.50% 的用户
// 内存消耗：15.9 MB, 在所有 C++ 提交中击败了61.65% 的用户

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
    bool dfs(TreeNode *leftNode, TreeNode *rightNode) {
        if (!leftNode && !rightNode) { return true; }
        if (!leftNode || !rightNode || leftNode->val != rightNode->val) { return false; }

        return dfs(leftNode->left, rightNode->right) &&
               dfs(leftNode->right, rightNode->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root ? dfs(root->left, root->right) : true;
    }
};