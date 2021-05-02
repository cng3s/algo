
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了74.46% 的用户

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        while (n) {
            ++ans;
            n = n & (n-1);
        }
        return ans;
    }
};