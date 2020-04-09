// 执行用时 :124 ms, 在所有 C++ 提交中击败了5.46% 的用户
// 内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
//

class Solution {
private:
    int _pull( int idx, vector<int>& nums, vector<int>& dp, int& ans ) {
        if ( dp[idx] != INT_MIN ) { return dp[idx]; }
        dp[idx] = 1;
        for ( int j = idx-1; j >= 0; --j ) {
            if ( nums[j] < nums[idx] ) { dp[idx] = max( dp[idx], _pull( j, nums, dp, ans )+1 ); }
        }
        ans = max( dp[idx], ans );
        return dp[idx];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        if ( nums.size() == 0 ) { return 0; }
        int ans = 0;
        vector<int> dp( nums.size(), INT_MIN );
        for ( int i = 0; i < nums.size(); ++i ) {
            _pull( i, nums, dp, ans );
        }
        return ans;
    }
};