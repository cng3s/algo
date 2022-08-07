// 执行用时：4 ms, 在所有 C++ 提交中击败了93.47% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了6.88% 的用户

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left; // prev
    Node* right; // next

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
public:
    void preTraverse(Node* root, vector<Node*>& ans) {
        if (root != nullptr) {
            preTraverse(root->left, ans);
            ans.emplace_back(root);
            preTraverse(root->right, ans);
        }
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) { return nullptr; }
        vector<Node*> preorder;
        preTraverse(root, preorder);
        int npreorder = preorder.size();

        for (int i = 0; i < npreorder; ++i) {
            cout << preorder[i]->val << " ";
            int preidx, nextidx = (i+1) % npreorder;
            if (i == 0) { preidx = npreorder - 1; }
            else { preidx = i-1; }
            
            preorder[i]->left = preorder[preidx];
            preorder[i]->right = preorder[nextidx];
        }

        return preorder[0];
    }
};