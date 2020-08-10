// 执行用时：32 ms, 在所有 C++ 提交中击败了80.65% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了95.76% 的用户

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cf{ 0 };
        auto res = l1, prev = l1;
        while (l1 != nullptr && l2 != nullptr) {
            l1->val = l1->val + l2->val + cf;
            cf = updateVal(l1->val);
            l1 = l1->next, l2 = l2->next;
            if (l1 != nullptr)
                prev = l1;
        }

        while (l1 != nullptr) {
            l1->val = l1->val + cf;
            cf = updateVal(l1->val);
            l1 = l1->next;
            if (l1 != nullptr)
                prev = l1;
        }

        if (l2 != nullptr) {
            prev->next = l2;
            prev = l2;
        }
        while (l2 != nullptr) {
            l2->val = l2->val + cf;
            cf = updateVal(l2->val);
            l2 = l2->next;
            if (l2 != nullptr)
                prev = l2;
        }

        if (cf == 1)
            prev->next = new ListNode(1);
        return res;
    }

private:
    int updateVal(int& val)
    {
        if (val >= 10) {
            val %= 10;
            return 1;
        }
        return 0;
    }
};