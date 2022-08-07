// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了97.50% 的用户

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        while (n) {
            if (n & 1) { ++ans; }
            n >>= 1;
        }
        return ans;
    }
};