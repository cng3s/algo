// 执行用时：24 ms, 在所有 C++ 提交中击败了95.48% 的用户
// 内存消耗：17 MB, 在所有 C++ 提交中击败了92.39% 的用户

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) { return 0; }

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ns = s.size(), ng = g.size(), ans = 0, sIx = 0;
        for (int i = 0; i < ng && sIx < ns;) {
            if (s[sIx] >= g[i]) { ++ans; ++i; }
            ++sIx;
        }

        return ans;
    }
};