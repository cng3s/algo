// 执行用时：20 ms, 在所有 C++ 提交中击败了80.46%的用户
// 内存消耗：25.8 MB, 在所有 C++ 提交中击败了23.22%的用户

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
    TreeNode* makeTree(const vector<int>& inorder, const vector<int>& postorder,
                       int inlo, int inhi, int postlo, int posthi) {

        //cout << "inorder: [" << inlo << "," << inhi << ") --- " << "postorder:[" << postlo << ", " << posthi << ")\n";

        if (inlo >= inhi || postlo >= posthi) { return nullptr; }

        int inIx = val_ix[postorder[posthi-1]];
        TreeNode *ret = new TreeNode(postorder[posthi-1]);

        ret->left = makeTree(inorder, postorder, inlo, inIx, postlo, postlo + (inIx - inlo));
        ret->right = makeTree(inorder, postorder, inIx + 1, inhi, postlo + (inIx - inlo), posthi - 1);

        return ret;
    }


public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); ++i) {
            val_ix[inorder[i]] = i;
        }

        return makeTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};