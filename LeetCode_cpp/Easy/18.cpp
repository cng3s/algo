// 执行用时：8 ms, 在所有 C++ 提交中击败了96.38% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了6.04% 的用户

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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head != nullptr) {
            if (head->val == val) { return head->next; }
            ListNode *delNode = head->next, *prevNode = head;

            while (delNode && delNode->val != val) {
                delNode = delNode->next;
                prevNode = prevNode->next;
            }

            if (delNode && delNode->val == val) { prevNode->next = delNode->next; }
        }

        return head;
    }
};