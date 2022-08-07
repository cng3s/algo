//ִ����ʱ��4 ms, ������ C++ �ύ�л�����88.56% ���û�
//�ڴ����ģ�13.5 MB, ������ C++ �ύ�л�����11.86% ���û�
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
    int res = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            res += root->left->val;

        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return res;
    }
};