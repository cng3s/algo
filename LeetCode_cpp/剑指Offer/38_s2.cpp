// 执行用时：84 ms, 在所有 C++ 提交中击败了47.57% 的用户
// 内存消耗：32.3 MB, 在所有 C++ 提交中击败了25.58% 的用户
// 84 ms	32.3 MB

// 注意，这边进行了一个更宽范围的剪枝优化，即当遇到相同的子串直接剪掉

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

        string subs = s.substr(0, ix+1);
        if (us.find(subs) == us.end()) { us.emplace(subs); }
        else { return; }

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