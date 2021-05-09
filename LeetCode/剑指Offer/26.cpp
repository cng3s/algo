// 执行用时：48 ms, 在所有 C++ 提交中击败了75.74% 的用户
// 内存消耗：32.8 MB, 在所有 C++ 提交中击败了80.14% 的用户

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
    void findB(TreeNode* root, TreeNode* B, vector<TreeNode*> &res) {
        if (root != nullptr) {
            if (root->val == B->val) { res.emplace_back(root); }
            findB(root->left, B, res);
            findB(root->right, B, res);
        }
    }

    bool compareAB(TreeNode* A, TreeNode* B) {
        if (B == nullptr) { return true; }
        if (!(A != nullptr && B != nullptr && A->val == B->val)) { return false; }

        bool flag = true;
        if (A != nullptr) {
            flag = compareAB(A->left, B->left);
            if (flag) { flag = compareAB(A->right, B->right); }
        }

        return flag;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) { return false; }

        vector<TreeNode*> poses;
        findB(A, B, poses);
        if (poses.empty()) { return false; }

        bool flag = false;
        for (int i = 0; i < poses.size() && !flag; ++i) {
            flag = compareAB(poses[i], B);
        }
        return flag;
    }
};