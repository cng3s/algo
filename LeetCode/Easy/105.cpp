// 执行用时：48 ms, 在所有 C++ 提交中击败了28.77%的用户
// 内存消耗：25.4 MB, 在所有 C++ 提交中击败了29.12%的用户



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
    TreeNode* makeTree(const vector<int>& preorder, const vector<int>& inorder,
                       int prelo, int prehi, int inlo, int inhi) {

                  
        if (inlo >= inhi || prelo >= prehi) { return nullptr; }

        TreeNode *ret = new TreeNode(preorder[prelo]);
        int inorderIdx =  inlo;

        for (; inorderIdx < inhi; ++inorderIdx) {
            if (inorder[inorderIdx] == preorder[prelo]) { break; }
        }

        ret->left = makeTree(preorder, inorder, prelo + 1, prelo + (inorderIdx - inlo) + 1, inlo, inorderIdx);
        ret->right = makeTree(preorder, inorder, prelo + (inorderIdx - inlo) + 1, prehi, inorderIdx + 1, inhi);


        return ret;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return makeTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};