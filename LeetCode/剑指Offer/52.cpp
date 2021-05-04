// 执行用时：52 ms, 在所有 C++ 提交中击败了64.29% 的用户
// 内存消耗：15.4 MB, 在所有 C++ 提交中击败了7.39% 的用户

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       stack<ListNode*> nodesA, nodesB;
       ListNode *prevNode = nullptr;

       while (headA) { nodesA.emplace(headA); headA = headA->next; }
       while (headB) { nodesB.emplace(headB); headB = headB->next; }

       while (!nodesA.empty() && !nodesB.empty()) {
           ListNode *nodeA = nodesA.top(), *nodeB = nodesB.top();
           nodesA.pop();
           nodesB.pop();
           if (nodeA == nodeB) { prevNode = nodeA; }
           else { return prevNode; }
       } 
       return prevNode;
    }
};