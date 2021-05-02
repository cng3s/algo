// 执行用时：4 ms, 在所有 C++ 提交中击败了75.87% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了58.24% 的用户

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int ns = s.size();
        if (n >= ns) {
            return s;
        }

        for (int i = 0; i < n; ++i) {
            s.push_back(s[i]);
        }
        return s.substr(n, s.size());
    }
};