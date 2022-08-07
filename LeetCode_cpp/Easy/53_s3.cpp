// 执行用时 :44 ms, 在所有 C++ 提交中击败了33.64% 的用户
// 内存消耗 :48.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
private:
    int _maxidx;
    int pull( vector<int>& nums, vector<int>& dp, int idx ) {
        if ( dp[idx] != -101 ) { return dp[idx]; }
        dp[idx] = max( nums[idx], nums[idx]+pull(nums, dp, idx-1) );
        if ( dp[idx] > dp[_maxidx] ) { _maxidx = idx; }
        return dp[idx];
    }

public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp( nums.size(), -101 );
        dp[0] = nums[0];
        pull( nums, dp, nums.size()-1 );
        return dp[_maxidx];
    }
};