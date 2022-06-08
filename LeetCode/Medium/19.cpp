// 执行用时：4 ms, 在所有 C++ 提交中击败了77.50%的用户
// 内存消耗：10.4 MB, 在所有 C++ 提交中击败了36.75%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listLength = 0;
        ListNode *nth = head, *cur = head, *prev = cur;

        while (nth) {
            ++listLength;
            nth = nth->next;
        }

        if (listLength < n) return head;
        // 删除头节点
        if (listLength == n) {
            prev = head;
            head = head->next;
            delete prev;
        } else if (n == 1) {
            // n == 1 && listLength != n , 删除末尾节点
            while (cur->next) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
        } else {
            nth = head;
            while (n && nth) { nth = nth->next; --n; }

            if (n != 0) {
                // n 没有减到0，说明链表长度不能满足删除倒数第k个节点
                return head;
            }

            // 删除中间节点
            while (nth) {
                prev = cur;
                cur = cur->next;
                nth = nth->next;
            }


            prev->next = cur->next;
            delete cur;
        }
        return head;
    }
};