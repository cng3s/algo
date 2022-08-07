// 执行用时：28 ms, 在所有 C++ 提交中击败了94.99% 的用户
// 内存消耗：22.7 MB, 在所有 C++ 提交中击败了82.74% 的用户

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
    TreeNode *ans;
    bool foundP, foundQ;

    bool judge(TreeNode* root, TreeNode *p, TreeNode *q, TreeNode *node) {
        if (root == nullptr) { return false; }
        if ((node == p && foundP) || (node == q && foundQ)) { return false; }
        if (root == p && node == p) { foundP = true; return true; }
        if (root == q && node == q) { foundQ = true; return true; }
        if (node->val < root->val) {
            return dfs(root->left, p, q);
        }
        else {
            return dfs(root->right, p, q);
        }
    }

    bool dfs(TreeNode* root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) { return false; }

        bool lson = judge(root, p, q, p);
        bool rson = judge(root, p, q, q);

        if ((lson && rson) ||
            ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        }

        return (root->val == p->val || root->val == q->val) || (lson || rson);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        foundP = false, foundQ = false;
        dfs(root, p, q);
        return ans;
    }
};