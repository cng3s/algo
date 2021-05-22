/*
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了82.68% 的用户
// 这个版本只是在上个版本基础上把两张哈希表合并为一张

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> origin_copy;
        
        Node* cur = head,  *ans = nullptr;;
        int cnt = 0;

        while (cur) {
            origin_copy[cur] = new Node(cur->val);
            if (cnt++ == 0) ans = origin_copy[cur];
            
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            if (cur->next == nullptr) { origin_copy[cur]->next = nullptr; }
            else { origin_copy[cur]->next = origin_copy[cur->next]; }

            if (cur->random == nullptr) { origin_copy[cur]->random = nullptr; }
            else { origin_copy[cur]->random = origin_copy[cur->random]; }

            ++cnt;
            cur = cur->next;
        }

        return ans;
    }
};