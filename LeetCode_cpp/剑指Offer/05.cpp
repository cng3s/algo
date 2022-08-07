// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了70.72% 的用户

class Solution {
public:
    string replaceSpace(string s) {
        int ns = s.size();
        string ans;
        for (int i = 0; i < ns; ++i) {
            if (s[i] != ' ') { ans.push_back(s[i]); }
            else { ans.append("%20"); }
        }
        return ans;
    }
};