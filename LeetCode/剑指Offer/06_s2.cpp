// 执行用时：4 ms, 在所有 C++ 提交中击败了87.43% 的用户
// 内存消耗：8.3 MB, 在所有 C++ 提交中击败了91.19% 的用户

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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        while (head) {
            ans.push_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};