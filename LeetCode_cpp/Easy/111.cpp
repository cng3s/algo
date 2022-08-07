// 执行用时：288 ms, 在所有 C++ 提交中击败了94.90%的用户
// 内存消耗：143.1 MB, 在所有 C++ 提交中击败了25.60%的用户

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) { return 0; }
        if (root->left == nullptr && root->right == nullptr) { return 1; }
        
        int leftdepth = INT_MAX, rightdepth = INT_MAX;
        if (root->left != nullptr) { leftdepth = minDepth(root->left); }
        if (root->right != nullptr) { rightdepth = minDepth(root->right); }

        return min(leftdepth, rightdepth) + 1;
    }
};