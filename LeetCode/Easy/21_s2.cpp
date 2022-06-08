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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode *ans = nullptr, *prev = nullptr, *head = nullptr;;


        if (list1 && !list2) return list1;
        else if (!list1 && list2) return list2;
        else if (!list1 && !list2) return head;
        else if (list1->val < list2->val) { ans = list1; list1 = list1->next; }
        else { ans = list2; list2 = list2->next; }

        head = ans;

        while (list1 && list2) {

            if (list1->val < list2->val) {
                prev = list1;
                list1 = list1->next;
                ans->next = prev;
            } else {
                prev = list2;
                list2 = list2->next;
                ans->next = prev;
            }

            ans = ans->next;

        }

        while (list1) { ans->next = list1; list1 = list1->next; ans = ans->next; }
        while (list2) { ans->next = list2; list2 = list2->next; ans = ans->next; }

        return head;
    }
};