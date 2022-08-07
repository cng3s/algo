// 执行用时：16 ms, 在所有 C++ 提交中击败了88.84% 的用户
// 内存消耗：13.9 MB, 在所有 C++ 提交中击败了67.97% 的用户

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
    TreeNode* ans;

    bool dfs(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (node == nullptr) { return false; }

        bool lson = dfs(node->left, p, q);
        bool rson = dfs(node->right, p, q);

        if ((lson && rson) ||
            ((node->val == p->val || node->val == q->val) && (lson || rson))) {
            ans = node;
        }

        return node->val == p->val || node->val == q->val || lson || rson;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;        
    }
};