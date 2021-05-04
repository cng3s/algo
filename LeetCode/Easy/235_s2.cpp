// 这个解法比s1好太多了,虽然测出来性能差不多,我认为是因为测试集的强度不够导致的。
// 执行用时：28 ms, 在所有 C++ 提交中击败了94.99% 的用户
// 内存消耗：22.8 MB, 在所有 C++ 提交中击败了50.33% 的用户

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = nullptr;
        while (true) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            else {
                break;
            }
        }

        return root;
    }
};