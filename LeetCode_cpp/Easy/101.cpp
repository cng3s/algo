// ִ����ʱ��4 ms, ������ C++ �ύ�л�����86.06% ���û�
// �ڴ����ģ�12.6 MB, ������ C++ �ύ�л�����39.55% ���û�
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