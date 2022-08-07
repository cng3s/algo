// 执行用时：20 ms, 在所有 C++ 提交中击败了90.49% 的用户
// 内存消耗：10.3 MB, 在所有 C++ 提交中击败了90.33% 的用户

class Solution {
public:
    char firstUniqChar(string s) {
        int vis[26] = { 0 };
        int ns = s.size();
        for (int i = 0; i < ns; ++i) { ++vis[s[i] - 'a']; }
        for (int i = 0; i < ns; ++i) {
            if (vis[s[i] - 'a'] == 1) return s[i];
        }
        return ' ';
    }
};