// 执行用时 :16 ms, 在所有 C++ 提交中击败了89.50% 的用户
// 内存消耗 :10.8 MB, 在所有 C++ 提交中击败了90.00%的用户
// 优化了： vector替换为原生数组，并且不反复调用size()函数
//

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[m+1][n+1];
        memset( dp, 0, sizeof(int)*(m+1)*(n+1) );

        for ( int i = 1; i <= m; ++i ) {
            for ( int j = 1; j <= n; ++j )
                dp[i][j] = ( text1[i-1] == text2[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]) );
        }
        return dp[m][n];
    }
};