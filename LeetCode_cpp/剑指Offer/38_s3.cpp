// 执行用时：56 ms, 在所有 C++ 提交中击败了69.94% 的用户
// 内存消耗：29.8 MB, 在所有 C++ 提交中击败了37.21% 的用户
// 56 ms	29.8 MB

class Solution {
private:
    vector<string> ans;

    void dfs(string &s, int ix) {
        if (ix == s.size() - 1) { ans.emplace_back(s); return; }

        set<char> sc;

        for (int i = ix; i < s.size(); ++i) {
            if (sc.find(s[i]) != sc.end()) { continue; }
            sc.emplace(s[i]);
            swap(s[i], s[ix]);
            dfs(s, ix+1);
            swap(s[i], s[ix]);
        }
    }

public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return ans;
    }
};