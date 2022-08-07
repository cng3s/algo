// ִ����ʱ��4 ms, ������ C++ �ύ�л�����46.56% ���û�
// �ڴ����ģ�8.6 MB, ������ C++ �ύ�л�����44.66% ���û�
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

public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> q;
        vector<int> ret;

        if (nullptr != root) { q.emplace(root); }
        while (!q.empty()) {
            TreeNode* cur = q.top();
            ret.emplace_back(cur->val);
            q.pop();
            if (nullptr != cur->right) { q.emplace(cur->right); }
            if (nullptr != cur->left) { q.emplace(cur->left); }
        }

        return ret;
    }
};