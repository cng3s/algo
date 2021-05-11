// 执行用时：4 ms, 在所有 C++ 提交中击败了96.84% 的用户
// 内存消耗：6.7 MB, 在所有 C++ 提交中击败了98.38% 的用户

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int vis[128] = {0}, ns = s.size(), ans = 0, start = 0;

        for (int i = 0; i < ns; ++i) {
            ++vis[s[i]];
            while (vis[s[i]] == 2) { --vis[s[start++]]; }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};