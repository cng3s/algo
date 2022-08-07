// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了80.56% 的用户

class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1, sum = 0;

        for (int i = 0; i < n; ++i) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }

        return a;
    }
};