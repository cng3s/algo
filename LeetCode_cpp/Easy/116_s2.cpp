// 执行用时：24 ms, 在所有 C++ 提交中击败了81.26%的用户
// 内存消耗：16.4 MB, 在所有 C++ 提交中击败了89.75%的用户

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void traverse(Node* root) {
        
        if (root->left == nullptr || root->right == nullptr) { return; }

        root->left->next = root->right;
        if (root->next != nullptr) { root->right->next = root->next->left; }

        traverse(root->left);
        traverse(root->right);
    }


public:
    Node* connect(Node* root) {
        if (root == nullptr) { return nullptr; }

        
        traverse(root);
        return root;
    }
};