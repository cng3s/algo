
// 执行用时：4 ms, 在所有 C++ 提交中击败了81.80% 的用户
// 内存消耗：12.2 MB, 在所有 C++ 提交中击败了56.87% 的用户

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> curNodes, nextNodes;
        queue<TreeNode*> *curPtr = &curNodes, *nextPtr = &nextNodes;
        vector<vector<int>> ans;


        if (root) { curPtr->emplace(root); }
        while (!curPtr->empty()) {
            vector<int> subans;

            while (!curPtr->empty()) {
                TreeNode* cur = curPtr->front();
                curPtr->pop();
                subans.emplace_back(cur->val);

                if (cur->left) { nextPtr->emplace(cur->left); }
                if (cur->right) { nextPtr->emplace(cur->right); }
            }
            ans.emplace_back(subans);
            swap(curPtr, nextPtr);
        }

        return ans;
    }
};