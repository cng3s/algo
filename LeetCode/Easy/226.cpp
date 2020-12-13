// ִ����ʱ��4 ms, ������ C++ �ύ�л�����60.15% ���û�
// �ڴ����ģ�9.4 MB, ������ C++ �ύ�л�����26.67% ���û�
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
    void invert1_(TreeNode* root) {
        if (root == nullptr) { return; }
        swap(root->left, root->right);
        invert1_(root->left);
        invert1_(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert1_(root);
        return root;
    }
};