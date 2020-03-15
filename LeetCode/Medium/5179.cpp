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
    int _get_tree_height(TreeNode* root, int height) {
        return root == nullptr ? 0 : max(_get_tree_height(root->left, height), _get_tree_height(root->right, height)) + 1;
    }
    
    int _get_balance_factor(TreeNode* root) {
        //cout << "_get_balance_factor: " << root->val << ", left height: " << (root->left != nullptr ? root->left->val : -1) << " " << getTreeHeight(root->left) << ", right height: " << (root->right != nullptr ? root->right->val : -1) << " " << getTreeHeight(root->right) << ", factor: " << getTreeHeight(root->left) - getTreeHeight(root->right) << endl;
        return getTreeHeight(root->left) - getTreeHeight(root->right);
    }
    
    TreeNode* _rotate_left(TreeNode* root) {
        TreeNode* ret = root->right;
        root->right = ret->left;
        ret->left = root;
        return ret;
    }   
    
    TreeNode* _rotate_right(TreeNode* root) {
        TreeNode* ret = root->left;
        root->left = ret->right;
        ret->right = root;
        return ret;
    }
    
public:
    
    // because TreeNode has not tree_height field
    // so we must get tree height by recursion
    int getTreeHeight(TreeNode* root) {
        return _get_tree_height(root, 0);
    }
    
    // do post order traverse
    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        root->left = balanceBST(root->left);
        root->right = balanceBST(root->right);
        
        int factor = _get_balance_factor(root);
        
        if (factor <= -2 && _get_balance_factor(root->right) <= 0) { // rr, do rotate left
            
            root = _rotate_left(root);
            root->left = balanceBST(root->left);
            root->right = balanceBST(root->right);
            //cout << "do_rotate_left: root: " << root->val << ", root->left: " << root->left->val << ", root->right: " << root->right->val << endl;
        } else if (factor >= 2 && _get_balance_factor(root->left) >= 0) { // ll, do rotate right
            
            root = _rotate_right(root);
            root->left = balanceBST(root->left);
            root->right = balanceBST(root->right);
            //cout << "do_rotate_right: root: " << root->val << ", root->left: " << root->left->val << ", root->right: " << root->right->val << endl;
        } else if (factor <= -2 && _get_balance_factor(root->right) > 0) { // rl, first tree->right do rotate left, then do rotate right
            
            root->right = _rotate_right(root->right);
            root = _rotate_left(root);
            root->left = balanceBST(root->left);
            root->right = balanceBST(root->right);
            // cout << "do_rotate_right_left: root: " << root->val << ", root->left: " << root->left->val << ", root->right: " << root->right->val << endl;
        } else if (factor >= 2 && _get_balance_factor(root->left) < 0) { // lr, first tree->left do rotate left, then tree root do rotate right 
            
            root->left = _rotate_left(root->left);
            root = _rotate_right(root);
            root->left = balanceBST(root->left);
            root->right = balanceBST(root->right);
            //cout << "do_rotate_left_right: root: " << root->val << ", root->left: " << root->left->val << ", root->right: " << root->right->val << endl;
        }
        
        return root;
    }
};