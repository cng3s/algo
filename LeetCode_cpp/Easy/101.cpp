// 执行用时：4 ms, 在所有 C++ 提交中击败了86.06% 的用户
// 内存消耗：12.6 MB, 在所有 C++ 提交中击败了39.55% 的用户
/**
 * Definitiok for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool check_(TreeNode* left, TreeNode* right) {
        if (nullptr == left && nullptr == right) { return true; }
        if ((nullptr != left && nullptr == right) ||
            (nullptr == left && nullptr != right)) { return false; }

        if ((nullptr == left->left && nullptr != right->right) ||
            (nullptr != left->left && nullptr == right->right) ||
            (nullptr == left->right && nullptr != right->left) ||
            (nullptr != left->right && nullptr == right->left) ||
            (left->val != right->val)) { return false; }

        bool ret = true;
        if (nullptr != left->left && nullptr != right->right) {
            if (left->left->val == right->right->val) { ret = ret & check_(left->left, right->right); }
            else { return false; }
            if (false == ret) { return false; }
        }
        if (nullptr != left->right && nullptr != right->left) {
            if (left->right->val == right->left->val) { ret = ret & check_(left->right, right->left); }
            else { return false; }
            if (false == ret) { return false; }
        }
        return true;
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (nullptr == root) { return true; }
        return check_(root->left, root->right);
    }
};