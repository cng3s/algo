// 执行用时：12 ms, 在所有 C++ 提交中击败了61.67% 的用户
// 内存消耗：19.5 MB, 在所有 C++ 提交中击败了34.00% 的用户
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
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int target, int sum, vector<int>& subans) {
        sum += root->val;
        //if (sum > target) { return; }
        subans.emplace_back(root->val);
        if (!root->left && !root->right) { 
            if (sum == target)
                ans.emplace_back(subans); 
        }
        else {
            if (root->left) { dfs(root->left, target, sum, subans); }
            if (root->right) { dfs(root->right, target, sum, subans); }
        }
        subans.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        vector<int> subans;
        if (root) { dfs(root, target, 0, subans); }
        return ans;
    }
};