#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 这个解法比解法一快了一倍
class Solution {
public:

    ListNode *list_head;

    bool dfs(ListNode* list, TreeNode* node) {
        if (list == nullptr)
            return true;
        if (node == nullptr)
            return false;
        if (list->val == node->val) {
            if (dfs(list->next, node->left)) { return true; }
            if (dfs(list->next, node->right)) { return true; }
        }

        // 当list->val != node->val时，接下来的遍历必须要对列表重头开始遍历
        // 否则会出现一个节点不匹配但接着遍历的问题
        if (list == list_head && dfs(list, node->left)) { return true; }
        if (list == list_head && dfs(list, node->right)) { return true; }
        return false;
    }

    // 先序遍历
    bool isSubPath(ListNode* head, TreeNode* root) {
        list_head = head;
        return dfs(head, root);
    }
};