// 执行用时 :80 ms, 在所有 C++ 提交中击败了21.68% 的用户
// 内存消耗 :26.2 MB, 在所有 C++ 提交中击败了5.14%的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int> _tree_nums; // 从小到大的树数
    int idx;

    void _in_order_traverse(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        _in_order_traverse(node->left);
        _tree_nums.push_back(node->val);
        _in_order_traverse(node->right);
    }

public:
    BSTIterator(TreeNode* root) : idx(-1) {
        _in_order_traverse(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return _tree_nums[++idx];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return idx < int(_tree_nums.size()) - 1;
    }
};