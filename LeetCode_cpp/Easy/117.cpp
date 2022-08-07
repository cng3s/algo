// 执行用时：12 ms, 在所有 C++ 提交中击败了92.24%的用户
// 内存消耗：17.2 MB, 在所有 C++ 提交中击败了66.15%的用户


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
public:
    Node* connect(Node* root) {
        if (root == nullptr) { return nullptr; }

        queue<Node*> q1, q2;
        queue<Node*> *cur = &q1, *next = &q2;

        cur->emplace(root);

        while (!cur->empty()) {

            while (!cur->empty()) {
                
                Node* node = cur->front();
                cur->pop();
                
                if (cur->empty()) {
                    node->next = nullptr;
                } else {
                    node->next = cur->front();
                }
                
                if (node->left != nullptr) { next->emplace(node->left); }
                if (node->right != nullptr) { next->emplace(node->right); }
            }

            swap(cur, next);
        }

        return root;

    }
};