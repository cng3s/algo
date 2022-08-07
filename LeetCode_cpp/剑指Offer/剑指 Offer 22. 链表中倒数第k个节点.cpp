// 显示详情
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了67.81% 的用户

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
        if (head == nullptr)
            return nullptr;
        
        ListNode *cur = head;
        for (int i = 1; i < k && cur != nullptr; ++i) {
            cur = cur->next;
        }

        while (cur->next != nullptr) {
            cur = cur->next;
            head = head->next;
        }

        return head;
    }
};