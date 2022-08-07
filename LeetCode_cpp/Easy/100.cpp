// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：10.1 MB, 在所有 C++ 提交中击败了41.05% 的用户
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
    bool traverse_(const TreeNode* p, const TreeNode* q) {
        if (nullptr == p && nullptr == q) { return true; }
        if ((nullptr == p && nullptr != q) ||
            (nullptr != p && nullptr == q)) { return false; }

        bool ret = true;
        if (p->val != q->val) { return false; }
        ret = traverse_(p->left, q->left);
        ret = ret & traverse_(p->right, q->right);
        return ret;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traverse_(p, q);
    }
};