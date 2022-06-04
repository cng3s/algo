// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了72.24% 的用户

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int k = INT_MAX / 10, t = INT_MIN / 10;

        while (x != 0) {
            if (ans == INT_MAX || ans == INT_MIN) return 0;
            if (ans > k || ans < t ) return 0;
            if (ans > 0 && ans * 10 < 0) return 0;
            if (ans < 0 && ans * 10 > 0) return 0;
            ans = ans * 10;

            int mod = x % 10;
            if (ans > 0 && ans + mod < 0) return 0;
            if (ans < 0 && ans + mod > 0) return 0;
            ans += mod;
            x /= 10;
        }
        return ans;
    }
};