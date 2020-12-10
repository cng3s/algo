
// 执行用时：4 ms, 在所有 C++ 提交中击败了46.67% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了13.22% 的用户


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        std::stack<TreeNode*> nodes;
        TreeNode* cur = root;

        do {

            if (nullptr != cur) {
                nodes.push(cur);
                cur = cur->left;
            }
            else {
                if (!nodes.empty()) {
                    cur = nodes.top();
                    ret.emplace_back(cur->val);
                    nodes.pop();
                    cur = cur->right;
                }
            }
        } while (nullptr != cur || !nodes.empty());

        return ret;
    }
};