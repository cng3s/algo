// 执行用时：4 ms, 在所有 C++ 提交中击败了87.43% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了21.65% 的用户
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
    void reverse(ListNode* node, vector<int> &res) {
        if (node == nullptr) { return; } 
        reverse(node->next, res);
        res.emplace_back(node->val);

    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        reverse(head, ans);
        return ans;
    }
};