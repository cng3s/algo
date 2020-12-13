// 执行用时：4 ms, 在所有 C++ 提交中击败了60.15% 的用户
// 内存消耗：9.4 MB, 在所有 C++ 提交中击败了26.67% 的用户
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
private:
    void invert1_(TreeNode* root) {
        if (root == nullptr) { return; }
        swap(root->left, root->right);
        invert1_(root->left);
        invert1_(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert1_(root);
        return root;
    }
};