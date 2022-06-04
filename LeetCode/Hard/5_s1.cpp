// 执行用时：432 ms, 在所有 C++ 提交中击败了33.95% 的用户
// 内存消耗：378 MB, 在所有 C++ 提交中击败了16.63% 的用户

class Solution {
public:
    string longestPalindrome(string s) {
        size_t n = s.size();
        if (n <= 1)  return s; 

        vector<vector<int>> dp(n, vector<int>(n));
        int maxlen = 1, begin = 0;

        for (size_t i = 0; i < n; ++i)
            dp[i][i] = true;

        for (int len = 2; len <= n; ++len) {
            for (int lo = 0; lo < n; ++lo) {
                int hi = len + lo - 1;
                
                // 越界
                if (hi >= n || hi < lo)    break;

                if (s[lo] != s[hi]) { dp[lo][hi] = false; }
                else {
                    // s[lo] == s[hi]
                    if (hi - lo < 3)      dp[lo][hi] = true;
                    else                  dp[lo][hi] = dp[lo+1][hi-1];
                    if (true == dp[lo][hi] && len > maxlen) {
                        maxlen = len;
                        begin = lo;
                    }
                }
            }
        } 

        return s.substr(begin, maxlen);
    }
};