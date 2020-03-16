// 执行用时 :8 ms, 在所有 C++ 提交中击败了51.49% 的用户
// 内存消耗 :13.6 MB, 在所有 C++ 提交中击败了14.70%的用户
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
    void _update_l2r(vector<vector<int>>& res, vector<TreeNode*>& level, int leftidx, int rightidx) {
        vector<int> vec;
        for (int i = leftidx; i <= rightidx; ++i) {
            vec.push_back(level[i]->val);
        }
        res.push_back(vec);
    }

    void _update_r2l(vector<vector<int>>& res, vector<TreeNode*>& level, int leftidx, int rightidx) {
        vector<int> vec;
        for (int i = rightidx; i >= leftidx; --i) {
            vec.push_back(level[i]->val);
        }
        res.push_back(vec);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        vector<TreeNode*> level;
        level.push_back(root);
        
        bool l2r = true;
        int level_beg = 0, level_end = 0, next_end = level_end;

        while (1) {
            
            // 层序遍历
            for (int i = level_beg; i <= level_end; ++i) {
                TreeNode* node = level[i];
                if (node->left) {
                    level.push_back( node->left );
                    ++next_end;
                }
                if (node->right) {
                    level.push_back(node->right);
                    ++next_end;
                }
            }

            // 更新res
            if (l2r) {
                _update_l2r(res, level, level_beg, level_end);
            } else {
                _update_r2l(res, level, level_beg, level_end);
            }

            if (next_end == level_end) { // 没有新的结点添加到level中，说明树全部遍历完毕
                break;
            }

            // 初始化下轮迭代
            l2r = !l2r;
            level_beg = level_end+1;
            level_end = next_end;
        }
        return res;
    }
};