// 执行用时：16 ms, 在所有 C++ 提交中击败了65.49% 的用户
// 内存消耗：21.6 MB, 在所有 C++ 提交中击败了6.11% 的用户

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
    bool isValid;

private:
    void checkBST(TreeNode* root, long minval, long maxval) {
        if (isValid == false) { return; }
        if (root->val == minval || root->val == maxval) { isValid = false; return; }
        
        if (nullptr != root->left) {
            if (maxval > (long)root->left->val &&
                minval < (long)root->left->val &&
                root->val > root->left->val) { checkBST(root->left, minval, root->val); }
            else { isValid = false; return; }
        }
        if (nullptr != root->right) {
            if (maxval > (long)root->right->val &&
                minval < (long)root->right->val &&
                root->val < root->right->val) { checkBST(root->right, root->val, maxval); }
            else { isValid = false; return; }
        }
    }

public:
    bool isValidBST(TreeNode* root) {
        isValid = true;
        checkBST(root, LONG_MIN, LONG_MAX);
        return isValid;
    }
};