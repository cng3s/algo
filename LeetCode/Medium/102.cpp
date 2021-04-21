// 执行用时：4 ms, 在所有 C++ 提交中击败了89.12% 的用户
// 内存消耗：11.8 MB, 在所有 C++ 提交中击败了18.41% 的用户

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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q1, q2, *cur = &q1, *next = &q2;

        if (nullptr != root) {
            cur->emplace(root);
            while (!cur->empty()) {
                vector<int> tmp;
                while (!cur->empty()) {
                    auto node = cur->front();
                    tmp.emplace_back(node->val);
                    if (nullptr != node->left) { next->emplace(node->left); }
                    if (nullptr != node->right) { next->emplace(node->right); }
                    cur->pop();
                }
                ret.emplace_back(tmp);
                swap(cur, next);
            }
        }

        return ret;
    }
};