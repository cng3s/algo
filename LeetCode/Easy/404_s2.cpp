//执行用时：4 ms, 在所有 C++ 提交中击败了88.56% 的用户
//内存消耗：13.5 MB, 在所有 C++ 提交中击败了11.86% 的用户
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
    int res = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            res += root->left->val;

        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return res;
    }
};