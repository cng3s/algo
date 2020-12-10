// 执行用时：36 ms, 在所有 C++ 提交中击败了84.55% 的用户
// 内存消耗：10.5 MB, 在所有 C++ 提交中击败了99.41% 的用户
class Solution {
public:
    char firstUniqChar(string s) {
        array<int, 26> table{};
        for (const auto c : s) {
            ++table[c-97];
        }
        for (const auto c : s) {
            if (table[c-97] == 1)
                return c;
        }
        return ' ';
    }
};