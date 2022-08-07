// ִ����ʱ��36 ms, ������ C++ �ύ�л�����97.42% ���û�
// �ڴ����ģ�12 MB, ������ C++ �ύ�л�����37.57% ���û�
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;

        queue<Node*> q1, q2, *cur = &q1, *next = &q2;
        if (nullptr != root) {
            cur->emplace(root);
            while (!cur->empty()) {
                vector<int> tmp;
                while (!cur->empty()) {
                    auto node = cur->front();
                    for (const auto child : node->children) { next->emplace(child); }
                    tmp.emplace_back(node->val);
                    cur->pop();
                }
                ret.emplace_back(std::move(tmp));
                swap(cur, next);
            }
        }

        return ret;
    }
};