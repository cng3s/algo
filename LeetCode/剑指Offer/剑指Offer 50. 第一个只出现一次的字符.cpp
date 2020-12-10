// 显示详情
// 执行用时：36 ms, 在所有 C++ 提交中击败了84.55% 的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了86.01% 的用户

class Solution {
public:
    char firstUniqChar(string s) {
        array<int, 128> table{};
        for (const auto c : s) {
            ++table[c];
        }
        for (const auto c : s) {
            if (table[c] == 1)
                return c;
        }
        return ' ';
    }
};