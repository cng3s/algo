// 执行用时：188 ms, 在所有 C++ 提交中击败了9.70% 的用户
// 内存消耗：25.9 MB, 在所有 C++ 提交中击败了57.54% 的用户
// 192 ms	25.9 MB

class Solution {
public:
    int ns;
    unordered_set<string> us;
    void dfs(string& s, int ix, vector<string>& ans) {
        if (ix == ns-1) {
            if (us.find(s) == us.end()) {
                ans.emplace_back(s);
                us.emplace(s);
            }
            return;
        }

        for (int i = ix+1; i < ns; ++i) {
            dfs(s, ix+1, ans);
            if (s[i] != s[ix]) {
                swap(s[i], s[ix]); 
                dfs(s, ix+1, ans);
                swap(s[i], s[ix]);
            }
        }
        
    }

    vector<string> permutation(string s) {
        vector<string> ans;

        ns = s.size();
        dfs(s, 0, ans);

        return ans;
    }
};