// 执行用时：8 ms, 在所有 C++ 提交中击败了63.84% 的用户
// 内存消耗：8 MB, 在所有 C++ 提交中击败了63.86% 的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* node, ListNode*& newHead) {
        if (node->next) {
            ListNode *nextNode = reverse(node->next, newHead);
            nextNode->next = node;
        }
        else {
            newHead = node;
        }
        return node;
    }

    ListNode* reverseList(ListNode* head) {
        if (!(head && head->next)) { return head; }
        ListNode* ans = nullptr;
        reverse(head, ans);
        head->next = nullptr;
        return ans;
    }
};