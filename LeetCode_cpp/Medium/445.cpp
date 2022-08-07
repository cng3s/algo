// 执行用时 :44 ms, 在所有 C++ 提交中击败了39.97% 的用户
// 内存消耗 :71 MB, 在所有 C++ 提交中击败了11.11%的用户

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
    ListNode* _reverse( ListNode* l, ListNode*& head ) {
        if ( l == nullptr ) { return nullptr; }

        ListNode* next = _reverse( l->next, head );
        if ( next == nullptr ) { head = l; }
        else { next->next = l; }
        
        return l;
    }

    void _reverse_list( ListNode*& l ) {
        if ( l == nullptr ) { return; }
        _reverse( l, l )->next = nullptr;
    }


public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        _reverse_list( l1 );
        _reverse_list( l2 );

        bool carry = 0;
        ListNode* l3 = nullptr, *curl3 = l3;
        while ( l1 != nullptr && l2 != nullptr ) {
            ListNode* node = new ListNode;
            node->val = l1->val + l2->val + carry;
            if ( l3 == nullptr )    { l3 = curl3 = node; }
            else                    { curl3->next = node; curl3 = curl3->next; }
            if ( curl3->val >= 10 ) { curl3->val %= 10; carry = 1; }
            else                    { carry = 0; }
            l1 = l1->next, l2 = l2->next;
        }


        while ( l1 != nullptr ) {
            ListNode* node = new ListNode( l1->val + carry );
            if ( node->val >= 10 )  { node->val %= 10; carry = 1; }
            else                    { carry = 0; }
            curl3->next = node;
            curl3 = curl3->next;
            l1 = l1->next;

        }

        while ( l2 != nullptr ) {
            ListNode* node = new ListNode( l2->val + carry );
            if ( node->val >= 10 ) { node->val %= 10; carry = 1; }
            else                   { carry = 0; }
            curl3->next = node;
            curl3 = curl3->next;
            l2 = l2->next;
        }

        if ( carry == 1 ) {
            ListNode* node = new ListNode( 1 );
            curl3->next = node;
        }

        _reverse_list( l3 );
        return l3;
    }
};