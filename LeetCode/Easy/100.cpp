// ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00% ���û�
// �ڴ����ģ�10.1 MB, ������ C++ �ύ�л�����41.05% ���û�
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