// ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
// �ڴ����ģ�11.8 MB, ������ C++ �ύ�л�����99.54%���û�
// 

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
    int traverse(TreeNode* root, int sum) {

        if (root == nullptr) { return 0; }

        int nextsum = sum * 10 + root->val, ret = 0;

        if (nullptr == root->left && nullptr == root->right) {
            return nextsum;
        }

        return traverse(root->left, nextsum) + traverse(root->right, nextsum);
    }
public:
    int sumNumbers(TreeNode* root) {
        return traverse(root, 0);
    }
};