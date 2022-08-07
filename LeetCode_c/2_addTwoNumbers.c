/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;

    struct ListNode *cur1 = l1, *cur2 = l2, *prev = cur1;
    for (; cur1 && cur2; cur1 = cur1->next, cur2 = cur2->next) {
        prev = cur1;
        cur1->val = carry + cur1->val + cur2->val;
        carry = cur1->val / 10;
        cur1->val %= 10;
    }

    if (cur2) {
        prev->next = cur2;
        cur1 = cur2;
    }

    while (cur1 && carry) {
        cur1->val = cur1->val + carry;
        carry = cur1->val / 10;
        cur1->val %= 10;
        prev = cur1;
        cur1 = cur1->next;
    }

    if (carry) {
        struct ListNode *node = (struct ListNode *) calloc(1, sizeof(struct ListNode));
        node->val = carry;
        prev->next = node;
    }

    return l1;
}