// 执行用时：4 ms, 在所有 C++ 提交中击败了87.50%的用户
// 内存消耗：11.3 MB, 在所有 C++ 提交中击败了78.47%的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> getNextLevelVals(const vector<TreeNode*>& curLevel) {
        vector<TreeNode*> res;
        for (const auto node : curLevel) {
            if (node->left != nullptr) { res.emplace_back(node->left); }
            if (node->right != nullptr) { res.emplace_back(node->right); }
        }
        return res;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) { return {}; }

        std::vector<TreeNode*> tmp;
        std::stack<vector<int>> levels;
        std::vector<std::vector<int>> res;

        tmp.emplace_back(root);
        res.emplace_back( std::vector{root->val} );


        while (!tmp.empty()) {
            tmp = getNextLevelVals(tmp);
            std::vector<int> tmpVals;

            if (tmp.empty()) { break; }


            for (int tmpIx = 0; tmpIx < tmp.size(); ++tmpIx) {
                tmpVals.emplace_back(tmp[tmpIx]->val);
            }

            res.emplace_back(std::move(tmpVals));
        }

        reverse(res.begin(), res.end());

        return res;
    }
};