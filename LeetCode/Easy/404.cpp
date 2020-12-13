//ִ����ʱ��8 ms, ������ C++ �ύ�л�����49.64% ���û�
//�ڴ����ģ�13.6 MB, ������ C++ �ύ�л�����6.46% ���û�
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
    void traverse_(TreeNode* root, int &sum, bool isleft) {
        if (root == nullptr) { return; }
        if (root ->left == nullptr && root->right == nullptr && isleft) { sum += root->val; return; }
        if (root->left != nullptr) traverse_(root->left, sum, true);
        if (root->right != nullptr) traverse_(root->right, sum, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;
        traverse_(root, ret, false);
        return ret;
    }
};