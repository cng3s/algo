// ִ����ʱ��28 ms, ������ C++ �ύ�л�����66.29% ���û�
// �ڴ����ģ�15.7 MB, ������ C++ �ύ�л�����57.42% ���û�

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> generate_(int beg, int end) {
        if (beg > end) { return { nullptr }; }
        else if (beg == end ) { return { new TreeNode(beg) }; } // ���������ܣ�����8ms���ڴ����ļ�����1mb

        vector<TreeNode*> ret;

        for (int i = beg; i <= end; ++i) {
            const auto leftTrees{ generate_(beg, i-1) };
            const auto rightTrees{ generate_(i+1, end) };

            for (const auto &leftTree : leftTrees) {
                for (const auto &rightTree : rightTrees) {
                    TreeNode* curNode{ new TreeNode(i) };
                    curNode->left = leftTree;
                    curNode->right = rightTree;
                    ret.emplace_back(curNode);
                }
            }
        }

        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return n == 0 ? vector<TreeNode*>() : generate_(1, n);
    }
};
