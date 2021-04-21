// 执行用时：4 ms, 在所有 C++ 提交中击败了47.71% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了12.06% 的用户
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
    void traverse_(TreeNode *root, vector<int>& ret) {
        if (nullptr != root->left) { traverse_(root->left, ret); }
        if (nullptr != root->right) { traverse_(root->right, ret); }
        ret.emplace_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (nullptr != root) { traverse_(root, ret); }
        return ret;
    }
};