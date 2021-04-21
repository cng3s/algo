// 执行用时：4 ms, 在所有 C++ 提交中击败了46.56% 的用户
// 内存消耗：8.5 MB, 在所有 C++ 提交中击败了63.18% 的用户
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
    void traverse_(TreeNode* root, vector<int>& ret) {
        if (nullptr == root) { return; }
        ret.emplace_back(root->val);
        traverse_(root->left, ret);
        traverse_(root->right, ret);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        traverse_(root, ret);
        return ret;
    }
};