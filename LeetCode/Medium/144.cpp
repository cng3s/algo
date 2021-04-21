// ִ����ʱ��4 ms, ������ C++ �ύ�л�����46.56% ���û�
// �ڴ����ģ�8.5 MB, ������ C++ �ύ�л�����63.18% ���û�
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
    void traverse_(TreeNode* root, vector<int>& ret) {
        if (nullptr == root) { return; }
        ret.emplace_back(root->val);
        traverse_(root->left, ret);
        traverse_(root->right, ret);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        traverse_(root, ret);
        return ret;
    }
};