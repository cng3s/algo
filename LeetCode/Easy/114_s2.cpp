// ִ����ʱ��16 ms, ������ C++ �ύ�л�����16.94% ���û�
// �ڴ����ģ�13.1 MB, ������ C++ �ύ�л�����12.49% ���û�
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
    void flatten(TreeNode* root) {
        if (nullptr == root) { return; }

        stack<TreeNode*> s;
        s.emplace(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (nullptr != cur->right) { s.emplace(cur->right); }
            if (nullptr != cur->left) { s.emplace(cur->left); }
            cur->left = nullptr;
            if (s.size() >= 1) { cur->right = s.top(); }
        }
    }
};