// 执行用时 :36 ms, 在所有 C++ 提交中击败了17.97% 的用户
// 内存消耗 :12.6 MB, 在所有 C++ 提交中击败了78.33%的用户

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp( text1.size()+1, vector<int>(text2.size()+1, 0) );

        for ( int i = 1; i <= text1.size(); ++i ) {
            for ( int j = 1; j <= text2.size(); ++j )
                dp[i][j] = ( text1[i-1] == text2[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]) );
        }
        return dp[text1.size()][text2.size()];
    }
};