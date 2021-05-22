// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了86.45% 的用户

class Solution {
public:
    int add(int a, int b) {
        return b == 0 ? a : add(a^b, (unsigned int)(a&b) << 1);
    }
};