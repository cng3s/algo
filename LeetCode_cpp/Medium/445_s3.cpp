// 执行用时 :72 ms, 在所有 C++ 提交中击败了7.17% 的用户
// 内存消耗 :73.9 MB, 在所有 C++ 提交中击败了11.11%的用户

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
        stack<int> s1, s2;
        for ( ; l1; l1 = l1->next ) { s1.push( l1->val ); }
        for ( ; l2; l2 = l2->next ) { s2.push( l2->val ); }

        ListNode *l3 = nullptr;
        int carry = 0;
        while ( !s1.empty() or !s2.empty() or carry ) {
            
            int n1 = s1.empty() ? 0 : s1.top(), n2 = s2.empty() ? 0 : s2.top();
            if ( !s1.empty() ) { s1.pop(); }
            if ( !s2.empty() ) { s2.pop(); }

            int sum = n1 + n2 + carry;
            carry = sum / 10;
            

            ListNode* cur = new ListNode( sum % 10 );
            cur->next = l3;
            l3 = cur;
        }

        return l3;
    }
};