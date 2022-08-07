// 执行用时：44 ms, 在所有 C++ 提交中击败了95.69% 的用户
// 内存消耗：14.2 MB, 在所有 C++ 提交中击败了59.33% 的用户
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        int cntA = 0, cntB = 0;
        ListNode *curA = headA, *curB = headB;
        while (curA) { ++lenA; curA = curA->next; }
        while (curB) { ++lenB; curB = curB->next; }

        curA = headA, curB = headB;
        while (curA && curB) {
            while ((lenA - cntA) < (lenB - cntB)) { ++cntB; curB = curB->next; }
            while ((lenA - cntA) > (lenB - cntB)) { ++cntA; curA = curA->next; }

            if (curA == curB) { return curA; }
            else { curA = curA->next; curB = curB->next; ++cntA; ++cntB; }
        }

        return nullptr;
    }
};