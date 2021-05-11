// 执行用时：4 ms, 在所有 C++ 提交中击败了93.47% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了69.88% 的用户

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    Node *pre, *head;

    void dfs(Node* root) {
        if (root == nullptr) { return; }

        dfs(root->left);
        if (pre != nullptr) { pre->right = root; }
        else { head = root; }

        root->left = pre;
        pre = root;
        dfs(root->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) { return nullptr; }
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};