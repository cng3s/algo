#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:

    bool dfs(ListNode* list, TreeNode* node) {
        if (list == nullptr)
            return true;
        if (node == nullptr)
            return false;
        if (list->val != node->val)
            return false;
        return dfs(list->next, node->left) || dfs(list->next, node->right);
    }

    // 先序遍历
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr)
            return false;
        if (root == nullptr)
            return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};