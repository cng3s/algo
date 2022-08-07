// 执行用时 :52 ms, 在所有 C++ 提交中击败了18.22% 的用户
// 内存消耗 :23.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxidx = 0;
        vector<int> dp( nums.size(), 0 );
        dp[0] = nums[0];

        for ( int i = 1; i < nums.size(); ++i ) {
            dp[i] = max( nums[i], nums[i]+dp[i-1] );
            if ( dp[i] > dp[maxidx]) { maxidx = i; }
        }
        return dp[maxidx];
    }
};