// ִ����ʱ��4 ms, ������ C++ �ύ�л�����47.71% ���û�
// �ڴ����ģ�8.7 MB, ������ C++ �ύ�л�����12.06% ���û�
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
    void traverse_(TreeNode *root, vector<int>& ret) {
        if (nullptr != root->left) { traverse_(root->left, ret); }
        if (nullptr != root->right) { traverse_(root->right, ret); }
        ret.emplace_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (nullptr != root) { traverse_(root, ret); }
        return ret;
    }
};