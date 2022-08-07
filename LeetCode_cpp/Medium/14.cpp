// 执行用时：4 ms, 在所有 C++ 提交中击败了66.07% 的用户
// 内存消耗：8.9 MB, 在所有 C++ 提交中击败了70.34% 的用户

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t n = strs.size(), cur = 0;
        bool stop = false;
        while (!strs.empty() && !stop) {
            if (cur >= strs[0].size())
                break;
            char c = strs[0][cur];

            for (size_t i = 1; i < n; ++i) {
                const auto & str = strs[i];
                if (cur >= str.size() || str[cur] != c) {
                    stop = true;
                    break;
                } 
            }
            if (stop )
                break;
            ++ cur;
        }

        return strs[0].substr(0, cur);
    }
};