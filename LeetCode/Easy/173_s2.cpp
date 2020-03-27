// 执行用时 :84 ms, 在所有 C++ 提交中击败了18.94% 的用户
// 内存消耗 :26 MB, 在所有 C++ 提交中击败了5.14%的用户

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
    stack<TreeNode*> s;
    
    void _push_all_left(TreeNode *node) {
        while (node != nullptr) {
            s.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        _push_all_left(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *cur = s.top();
        s.pop();
        if (cur->right != nullptr) {
            _push_all_left(cur->right);
        }
        return cur->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */