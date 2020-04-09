// 执行用时 :100 ms, 在所有 C++ 提交中击败了10.08% 的用户
// 内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户
//

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> dp( nums.size(), 1 );
        for ( int i = 0; i < nums.size(); ++i ) {
            for ( int j = i-1; j >= 0; --j ) {
                if ( nums[i] > nums[j] ) { dp[i] = max( dp[i], dp[j]+1 ); }
            }
            ans = max( dp[i], ans );
        }
        return ans;
    }
};