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
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            ++size;
            cur = cur->next;
        }
        size >>= 1;
        for (int i = 0; i < size; ++i) {
            head = head->next;
        }
        cout << endl;
        return head;
    }
};