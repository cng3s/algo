// 执行用时：4 ms, 在所有 C++ 提交中击败了98.87% 的用户
// 内存消耗：11.2 MB, 在所有 C++ 提交中击败了11.17% 的用户

/*
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
    const int NIL = -10001;
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> nodeIx;
        unordered_map<int, Node*> copyIx;
        
        Node* cur = head;
        int cnt = 0;
        while (cur) { nodeIx[cur] = cnt++; cur = cur->next; }

        cur = head;
        cnt = 0;
        while (cur) {
            copyIx[cnt++] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        cnt = 0;
        while (cur) {
            if (cur->next == nullptr) { copyIx[cnt]->next = nullptr; }
            else { copyIx[cnt]->next = copyIx[nodeIx[cur->next]]; }

            if (cur->random == nullptr) { copyIx[cnt]->random = nullptr; }
            else { copyIx[cnt]->random = copyIx[nodeIx[cur->random]]; }
            
            ++cnt;
            cur = cur->next;
        }

        return copyIx[0];
    }
};