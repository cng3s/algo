// ִ����ʱ��8 ms, ������ C++ �ύ�л�����45.65% ���û�
// �ڴ����ģ�13 MB, ������ C++ �ύ�л�����5.06% ���û�
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
private:
    bool is_both_same_(const TreeNode* lhs, const TreeNode* rhs) const {
        return (lhs == nullptr && rhs == nullptr) || (lhs != nullptr && rhs != nullptr);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (nullptr == root) { return true; }
        if (!is_both_same_(root->left, root->right)) { return false; }

        queue<TreeNode*> qleft, qright;
        if (nullptr != root->left) { qleft.emplace(root->left); }
        if (nullptr != root->right) { qright.emplace(root->right); }

        while (!qleft.empty() && !qright.empty()) {
            TreeNode *lhs = qleft.front(), *rhs = qright.front();
            if (lhs->val != rhs->val ||
                !is_both_same_(lhs->left, rhs->right) ||
                !is_both_same_(lhs->right, rhs->left)) { return false; }
            if (nullptr != lhs->left) {
                qleft.emplace(lhs->left);
                qright.emplace(rhs->right);
            }
            if (nullptr != lhs->right) {
                qleft.emplace(lhs->right);
                qright.emplace(rhs->left);
            }
            qleft.pop();
            qright.pop();
        }
        return true;
    }
};