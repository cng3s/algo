//执行用时 :8 ms, 在所有 C++ 提交中击败了51.49% 的用户
//内存消耗 :13.6 MB, 在所有 C++ 提交中击败了15.45%的用户

// 思路：
// 轮换两个vector，分别存放当前 level order 和 下一层的 level order
// 轮换使用 从左往右 或 从右往左 遍历当前的 level order vector 并添加到 res中
// 最终res即是锯齿型层次遍历

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
    void _update_l2r(vector<TreeNode*>& cur, vector<vector<int>>& res) {
        vector<int> vec;
        for (auto it : cur) {
            vec.push_back(it->val);
        }
        res.push_back(vec);
    }

    void _update_r2l(vector<TreeNode*>& cur, vector<vector<int>>& res) {
        vector<int> vec;
        for (int i = cur.size()-1; i >= 0; --i) {
            vec.push_back(cur[i]->val);
        }
        res.push_back(vec);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        vector<TreeNode*> vec1, vec2; // 轮换存放当前层和下一层的层序遍历的结果
        vector<TreeNode*> &cur = vec1, &next = vec2;
        bool l2r = true; // 标记是从左往右(true)还是从右往左(false)

        vec1.push_back(root);

        while (!cur.empty()) {

            // 层序遍历添加TreeNode*到next
            for (auto it : cur) {
                if (it->left) {
                    next.push_back(it->left);
                }
                if (it->right) {
                    next.push_back(it->right);
                }
            }

            // 更新res
            if (l2r) {
                _update_l2r(cur, res);
            } else {
                _update_r2l(cur, res);
            }

            // 初始化下一轮的操作
            cur.clear();
            swap(cur, next);
            l2r = !l2r;
        }

        return res;
    }
};