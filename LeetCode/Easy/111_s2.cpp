
// 执行用时：264 ms, 在所有 C++ 提交中击败了99.65%的用户
// 内存消耗：141.3 MB, 在所有 C++ 提交中击败了58.91%的用户

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
public:
    int minDepth(TreeNode* root) {
        int depth = 0;

        queue<TreeNode*> q1, q2;
        queue<TreeNode*> *cur = &q1, *next = &q2;

        if (root != nullptr) { cur->emplace(root); }

        bool found = false;

        while (!cur->empty()) {
            
            ++depth;

            while (!cur->empty()) {
                TreeNode* curnode = cur->front();
                cur->pop();
                if (curnode->left == nullptr && curnode->right == nullptr) {
                    found = true;
                    break;
                }

                if (curnode->left != nullptr) { next->emplace(curnode->left); }
                if (curnode->right != nullptr) { next->emplace(curnode->right); }
            }

            if (found) { break; }

            swap(cur, next);
        }

        return depth;
    }
};