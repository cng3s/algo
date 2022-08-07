// 执行用时：4 ms, 在所有 C++ 提交中击败了46.67% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了14.56% 的用户

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
private:
    void inorder_(TreeNode* root, vector<int>& v) {
        if (nullptr == root) { return; }
        inorder_(root->left, v);
        v.emplace_back(root->val);
        inorder_(root->right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder_(root, ret);
        return ret;
    }
};