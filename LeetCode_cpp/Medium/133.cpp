// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：9.4 MB, 在所有 C++ 提交中击败了5.08%的用户

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    bool traversed[101];
    Node* newnodes[101];


private:
    void createNodes(Node* node) {
        if (nullptr == node || traversed[node->val]) { return; }

        Node *copynode = new Node(node->val);
        newnodes[node->val] = copynode;
        traversed[node->val] = true;

        int nneighbors = node->neighbors.size();
        for (int i = 0; i < nneighbors; ++i) { createNodes(node->neighbors[i]); }
    }


    Node * clone(Node *node) {

        if (nullptr == node || traversed[node->val]) { return nullptr; }

        Node *copynode = newnodes[node->val];
        traversed[node->val] = true;

        int nneighbors = node->neighbors.size();
        for (int i = 0; i < nneighbors; ++i) {
            copynode->neighbors.emplace_back(newnodes[node->neighbors[i]->val]);
            clone(node->neighbors[i]);
        }

        return copynode;
    }

public:


    Node* cloneGraph(Node* node) {
        if (nullptr == node) { return nullptr; }


        fill(traversed, traversed + 101, false);

        createNodes(node);

        fill(traversed, traversed + 101, false);

        return clone(node);
    }
};