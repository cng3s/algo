// 执行用时：44 ms, 在所有 C++ 提交中击败了89.19% 的用户
// 内存消耗：32.8 MB, 在所有 C++ 提交中击败了73.12% 的用户

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
public:
    bool recur(TreeNode* A, TreeNode* B) {
        if (B == nullptr) { return true; }
        if (A == nullptr || A->val != B->val) { return false; }
        return recur(A->left, B->left) && recur(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
};