// 执行用时：4 ms, 在所有 C++ 提交中击败了95.68% 的用户
// 内存消耗：8 MB, 在所有 C++ 提交中击败了85.75% 的用户

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

    ListNode* reverseList(ListNode* head) {
        if (!(head && head->next)) { return head; }

        ListNode *cur = head, *next = head->next, *next2th = head->next->next;
        head->next = nullptr;

        while (next) {
            next->next = cur;
            cur = next;
            next = next2th;
            if (next2th) { next2th = next2th->next; }
        }

        return cur;
    }
};