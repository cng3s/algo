
/*
执行用时：16 ms, 在所有 C++ 提交中击败了97.64%的用户
内存消耗：24 MB, 在所有 C++ 提交中击败了65.72%的用户
*/


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

    // nums[lo, hi)
    TreeNode* makeTree(vector<int>& nums, int lo, int hi) {
        if (hi <= lo) { return nullptr; }
        int mid = (lo + hi - 1) / 2;
        
        TreeNode* ret = new TreeNode(nums[mid]);
        ret->left = makeTree(nums, lo, mid);
        ret->right = makeTree(nums, mid+1, hi);

        return ret;
    }


public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if (nums.empty()) { return nullptr; }

        return makeTree(nums, 0, nums.size());
    }
};

