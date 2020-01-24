/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 本题不能用delete删除root,不然leetcode oj会报错
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }
        return root;
    }
};