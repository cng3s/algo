// 执行用时：12 ms, 在所有 C++ 提交中击败了98.53% 的用户
// 内存消耗：23.5 MB, 在所有 C++ 提交中击败了56.87% 的用户

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
    tuple<bool, int> pinkKthLargest(TreeNode* root, int& th, int k) {
        if (root == nullptr) { return { false, 0 }; }

        auto [res, val] = pinkKthLargest(root->right, th, k);
        if (res) { return { true, val }; }

        ++th;
        
        if (th == k) { return { true, root->val }; }

        auto [res2, val2] = pinkKthLargest(root->left, th, k);
        if (res2) { return { true, val2 }; }

        return { false , 0 };
    }    
    int kthLargest(TreeNode* root, int k) {
        int th = 0;
        auto [res, val] = pinkKthLargest(root, th, k);
        return val;
    }
};