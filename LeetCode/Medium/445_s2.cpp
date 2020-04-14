// 执行用时 :60 ms, 在所有 C++ 提交中击败了16.66% 的用户
// 内存消耗 :73.8 MB, 在所有 C++ 提交中击败了11.11%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void _put_stack_elements_to_list( stack<int>& s, ListNode*& l, bool& carry ) {
        while ( !s.empty() ) {
            int val = s.top() + carry;
            s.pop();

            if ( val >= 10 ) { val %= 10; carry = true; }
            else { carry = false; }


            ListNode* tmp = new ListNode( val );
            tmp->next = l->next;
            l->next = tmp;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        for ( ListNode* cur1 = l1; cur1 != nullptr; cur1 = cur1->next ) { s1.push( cur1->val ); }
        for ( ListNode* cur2 = l2; cur2 != nullptr; cur2 = cur2->next ) { s2.push( cur2->val ); }

        bool carry = false;
        ListNode* l3 = new ListNode(-1), * cur = l3;
        while ( !s1.empty() && !s2.empty() ) {
            int val = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            
            if ( val >= 10 ) { val %= 10; carry = true; }
            else { carry = false; }
            
            ListNode* tmp = new ListNode( val );
            tmp->next = l3->next;
            l3->next = tmp;
        }

        // 把 s1 或 s2中没放进去的元素放入list
        _put_stack_elements_to_list( s1, l3, carry );
        _put_stack_elements_to_list( s2, l3, carry );

        if ( carry ) { 
            ListNode* tmp = new ListNode( 1 );
            tmp->next = l3->next;
            l3->next = tmp;
        }

        cur = l3->next;
        delete( l3 );
        return cur;
    }
};