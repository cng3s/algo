// 执行用时：4 ms, 在所有 C++ 提交中击败了76.52% 的用户
// 内存消耗：10.2 MB, 在所有 C++ 提交中击败了82.07% 的用户

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
    ListNode* getKthFromEnd(ListNode* head, int k) {

        ListNode* kNext = head;
        --k;
        while (k && kNext) { kNext = kNext->next; --k; }
        if (k) {
            return head;
        }
        while (kNext->next) {
            head = head->next;
            kNext = kNext->next;
        }
        return head;
    }
};