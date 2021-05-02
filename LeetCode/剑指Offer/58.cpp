// 执行用时：4 ms, 在所有 C++ 提交中击败了75.87% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了56.71% 的用户


class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int ns = s.size();

        if (ns <= n) {
            return s;
        }

        string ans;
        for (int i = n; i < ns; ++i) {
            ans.push_back(s[i]);
        }
        for (int i = 0; i < n; ++i) {
            ans.push_back(s[i]);
        }
        return ans;
    }
};