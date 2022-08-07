// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：12.3 MB, 在所有 C++ 提交中击败了27.36% 的用户

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
        if (!root) { return {}; }
        deque<TreeNode*> q1, q2;
        deque<TreeNode*> *cur = &q1, *next = &q2;
        vector<vector<int>> ans;

        cur->emplace_back(root);
        bool flag = false;
        while (!cur->empty()) {
            vector<int> subans;
            while (!cur->empty()) {
                TreeNode* x = cur->back();
                cur->pop_back();
                subans.emplace_back(x->val);
                if (!flag) {
                    //cout << x->val << " ";
                    if (x->left) { next->emplace_back(x->left); }
                    if (x->right) { next->emplace_back(x->right); } 
                } else {
                    //cout << x->val << " ";
                    if (x->right) { next->emplace_back(x->right); }
                    if (x->left) { next->emplace_back(x->left); }
                }
            }
            //cout << endl;
            swap(cur, next);
            flag = !flag;
            ans.emplace_back(subans);
        }
        return ans;
    }
};