// 执行用时 :4 ms, 在所有 C++ 提交中击败了84.38% 的用户
// 内存消耗 :13.9 MB, 在所有 C++ 提交中击败了9.30%的用户
// 双端队列的做法
// 宏观上看还是正常的层次遍历，细节上使用了双端队列来控制 从左向右 和 从右向左 的顺序


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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        bool l2r = true;
        deque<int> dq;
        queue<TreeNode*> levelNodes;
        levelNodes.push(root);
        levelNodes.push(nullptr);

        while (!levelNodes.empty()) {
            // init
            TreeNode* cur = levelNodes.front();
            levelNodes.pop();

            // do something
            if (cur) {
                // if cur != nullptr, that means this level is not end;
                // 1. we should push cur->left and cur->right into levelNodes
                // 2. we should push cur->val into dq by zigzag level order
                if (cur->left) {
                    levelNodes.push(cur->left);
                }
                if (cur->right) {
                    levelNodes.push(cur->right);
                }
                if (l2r) {
                    dq.push_back(cur->val);
                } else {
                    dq.push_front(cur->val);
                }

            } else {
                // if cur == nullptr, that means this level is end;
                // 1. we should tran dq into vec
                // 2. we should push_back vec into res
                // 3. update for next level
                vector<int> vec;
                for (auto it : dq) {
                    vec.push_back(it);
                }
                if (!levelNodes.empty()) {
                    levelNodes.push(nullptr);
                }
                res.push_back(vec);
                dq.clear();
                l2r = !l2r;
            }
        }

        return res;
    }
};