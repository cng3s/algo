// 执行用时：4 ms, 在所有 C++ 提交中击败了86.07% 的用户
// 内存消耗：16.6 MB, 在所有 C++ 提交中击败了5.09% 的用户

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
    bool isSymmetric(TreeNode* root) {
        if (!root) { return true; }

        deque<TreeNode*> curNodes, nextNodes;
        deque<TreeNode*> *cur = &curNodes, *next = &nextNodes;

        if (root->left && root->right) {
            cur->emplace_front(root->left);
            cur->emplace_back(root->right);
        } else if (!root->left && !root->right) {
        } else {
            return false;
        }

        while (!cur->empty()) {
            while (!cur->empty()) {
                TreeNode *leftNode = cur->front(), *rightNode = cur->back();
                cur->pop_front();
                cur->pop_back();

                if (leftNode->val != rightNode->val) { return false; }

                if (leftNode->left && rightNode->right) {
                    next->emplace_front(leftNode->left);
                    next->emplace_back(rightNode->right);
                } else if (!leftNode->left && !rightNode->right) {
                } else {
                    return false;
                }

                if (leftNode->right && rightNode->left) {
                    next->emplace_front(leftNode->right);
                    next->emplace_back(rightNode->left);
                } else if (!leftNode->right && !rightNode->left) {
                } else {
                    return false;
                }
            }
            swap(cur, next);
        }

        return true;
    }
};