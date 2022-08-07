/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *dummy = (struct ListNode*) malloc(sizeof(struct ListNode)), *cur = dummy;
    int carry = 0;
    while (l1 || l2) {
        struct ListNode *node = (struct ListNode*) calloc(1, sizeof(struct ListNode));
        node->val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = node->val / 10;
        node->val %= 10;
        cur->next = node;
        cur = cur->next;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry) {
        struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        cur->next = node;
    }
    
    struct ListNode *ans = dummy->next;
    free(dummy);
    return ans;
}