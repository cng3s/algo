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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( l1 == nullptr )        { return l2; }
        else if ( l2 == nullptr )   { return l1; }

        ListNode newl, *newcur = &newl;
        
        while ( l1 and l2 ) {
            if ( l1->val < l2->val ) {
                newcur->next = l1;
                l1 = l1->next;
            } else {
                newcur->next = l2;
                l2 = l2->next;
            }
            newcur = newcur->next;
        }

        while ( l1 ) { newcur->next = l1; l1 = l1->next; newcur = newcur->next; }
        while ( l2 ) { newcur->next = l2; l2 = l2->next; newcur = newcur->next; }
        return newl.next;
    }
};