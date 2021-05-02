// 执行用时：16 ms, 在所有 C++ 提交中击败了88.80% 的用户
// 内存消耗：17 MB, 在所有 C++ 提交中击败了8.41% 的用户

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
    bool traverse(TreeNode* node, TreeNode *target, vector<TreeNode*> &path) {
        if (node == nullptr) { return false; }
        if (node == target) { path.emplace_back(node); return true; }

        bool succ = false;
        if (!(succ = traverse(node->left, target, path))) {
            succ = traverse(node->right, target, path);
        }
        if (succ) { path.emplace_back(node); }
        
        return succ;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, qPath;
        traverse(root, p, pPath);
        traverse(root, q, qPath);

        TreeNode *ans = nullptr;
        int npPath = pPath.size(), nqPath = qPath.size(); 
        for (int i = 0, j = 0; i < npPath && j < nqPath;) {

            if (npPath < nqPath && (nqPath - j > npPath)) {
                if (pPath[i] == qPath[j]) { return pPath[i]; }
                ++j;
            }
            else if (npPath > nqPath && (npPath - i > nqPath)) {
                if (pPath[i] == qPath[j]) { return pPath[i]; }
                ++i;
            }
            else {
                if (pPath[i] == qPath[j]) { return pPath[i]; }
                ++i;
                ++j;
            }
            
        }
        return nullptr;
    }
};