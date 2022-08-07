// 执行用时：4 ms, 在所有 C++ 提交中击败了48.87% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了80.92% 的用户
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
        if (root != nullptr) { 
            TreeNode* right = mirrorTree(root->left);
            TreeNode* left = mirrorTree(root->right);
            root->left = left;
            root->right = right;
        }

        return root;
    }
};