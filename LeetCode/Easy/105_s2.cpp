// 执行用时：12 ms, 在所有 C++ 提交中击败了97.73%的用户
// 内存消耗：25.7 MB, 在所有 C++ 提交中击败了22.40%的用户



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
    unordered_map<int, int> val_ix;


private:
    TreeNode* makeTree(const vector<int>& preorder, const vector<int>& inorder,
                       int prelo, int prehi, int inlo, int inhi) {

                  
        if (inlo >= inhi || prelo >= prehi) { return nullptr; }

        TreeNode *ret = new TreeNode(preorder[prelo]);
        int inorderIdx =  val_ix[preorder[prelo]];


        ret->left = makeTree(preorder, inorder, prelo + 1, prelo + (inorderIdx - inlo) + 1, inlo, inorderIdx);
        ret->right = makeTree(preorder, inorder, prelo + (inorderIdx - inlo) + 1, prehi, inorderIdx + 1, inhi);


        return ret;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); ++i) {
            val_ix[inorder[i]] = i;
        }

        return makeTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};