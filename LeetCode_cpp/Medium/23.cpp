// 执行用时：20 ms, 在所有 C++ 提交中击败了77.77%的用户
// 内存消耗：13.7 MB, 在所有 C++ 提交中击败了17.47%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    struct entry {
        int val;
        ListNode *ptr;
        bool operator < (const entry &rhs) const  { return val > rhs.val; }
    };
            

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<entry> pq;
        ListNode *tmp;

        for (auto list : lists) {
            tmp = list;
            while (tmp) { pq.emplace(entry{tmp->val, tmp}); tmp = tmp->next;  }
        }

        if (pq.empty()) return nullptr;

        ListNode *list = pq.top().ptr;
        tmp = list;
        pq.pop();

        while (!pq.empty()) {
            tmp->next = pq.top().ptr; 
            pq.pop();
            tmp = tmp->next;;
        }
        // cout << "fuck:" << tmp->val << "," << tmp->next << endl;
        tmp->next = nullptr;

        return list;
    }
};