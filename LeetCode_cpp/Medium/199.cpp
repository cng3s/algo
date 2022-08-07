// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :11.9 MB, 在所有 C++ 提交中击败了9.09%的用户

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if ( root == nullptr )  { return ans; }
        queue<pair<TreeNode*, int>> q;
        int maxdepth = -1, curdepth = 0;

        q.emplace(root, 0);
        while ( !q.empty() ) {
            auto [tree, depth] = q.front();
            q.pop();
            if ( tree->right )  q.emplace(tree->right, depth+1);
            if ( tree->left )   q.emplace(tree->left, depth+1);
            if ( depth > maxdepth ) { 
                ans.emplace_back( tree->val );
                maxdepth = max(maxdepth, depth);
            }
        }

        return ans;
    }
};