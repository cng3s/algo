// 执行用时：12 ms, 在所有 C++ 提交中击败了96.21% 的用户
// 内存消耗：25.7 MB, 在所有 C++ 提交中击败了35.26% 的用户

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
private:
    unordered_map<int, int> table;

    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder,
                    int preorderLeft, int preorderRight,
                    int inorderLeft, int inorderRight) {
        
        if (inorderLeft > inorderRight) { return nullptr; }

        int inorderRoot = table[preorder[preorderLeft]];
        int leftTreeSize = inorderRoot - inorderLeft;

        TreeNode *root = new TreeNode(preorder[preorderLeft]);
        root->left = build(preorder, inorder, preorderLeft+1, preorderLeft+leftTreeSize, inorderLeft, inorderRoot-1);
        root->right = build(preorder, inorder, preorderLeft+leftTreeSize+1, preorderRight, inorderRoot+1, inorderRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ninorder = inorder.size();
        for (int i = 0; i < ninorder; ++i) {
            table[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, ninorder-1, 0, ninorder-1);
    }
};