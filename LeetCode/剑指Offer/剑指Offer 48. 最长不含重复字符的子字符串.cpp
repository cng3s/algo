// 执行用时：80 ms, 在所有 C++ 提交中击败了12.17% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了100.00% 的用户
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int strsize = s.size();
        int res = INT_MIN;
        
        for (int i = 0; i < strsize; ++i) {
            if (res > strsize - i)
                break;
            int count = 0;
            array<int, 128> table{};
            for (size_t cur = i; cur < strsize; ++cur) {
                if (table[s[cur]] == 1)
                    break;
                ++table[s[cur]];
                ++count;
            }
            if (count > res)
                res = count;
        }

        return res;
    }
};