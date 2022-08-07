// 执行用时：16 ms, 在所有 C++ 提交中击败了84.78% 的用户
// 内存消耗：24.8 MB, 在所有 C++ 提交中击败了60.22% 的用户

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
private:
    unordered_map<int, int> table;

public:
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder,
                    int preorderLeft, int preorderRight,
                    int inorderLeft, int inorderRight) {
        
        if (preorderLeft > preorderRight) { return nullptr; }

        int preorderRoot = preorderLeft;
        int inorderRoot = table[preorder[preorderRoot]];

        TreeNode *root = new TreeNode(preorder[preorderRoot]);
        int leftTreeSize = inorderRoot - inorderLeft;
        root->left = build(preorder, inorder, preorderLeft+1, preorderRoot+leftTreeSize, inorderLeft, inorderRoot-1);
        root->right = build(preorder, inorder, preorderLeft+leftTreeSize+1, preorderRight, inorderRoot+1, inorderRight);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) { table[inorder[i]] = i; }
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
};