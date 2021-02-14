// 执行用时：12 ms, 在所有 C++ 提交中击败了50.49% 的用户
// 内存消耗：13.3 MB, 在所有 C++ 提交中击败了5.01% 的用户
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
    void preOrder_(TreeNode* root, vector<TreeNode*>& res)
    {
        if (nullptr == root) { return; }
        res.emplace_back(root);
        preOrder_(root->left, res);
        preOrder_(root->right, res);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        preOrder_(root, nodes);
        int nnodes = nodes.size();
        for (int i = 0; i < nnodes - 1; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }
    }
};