// 执行用时 :28 ms, 在所有 C++ 提交中击败了37.88% 的用户
// 内存消耗 :12.6 MB, 在所有 C++ 提交中击败了78.33%的用户


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp( text1.size(), vector<int>(text2.size(), 0) );

        dp[0][0] = ( text1[0] == text2[0] );
        for ( int i = 1; i < text1.size(); ++i ) { dp[i][0] = dp[i-1][0] == 1 ? 1 : text1[i] == text2[0]; } 
        for ( int i = 1; i < text2.size(); ++i ) { dp[0][i] = dp[0][i-1] == 1 ? 1 : text1[0] == text2[i]; }

        for ( int i = 1; i < text1.size(); ++i ) {
            for ( int j = 1; j < text2.size(); ++j )
                dp[i][j] = ( text1[i] == text2[j] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]) );
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};