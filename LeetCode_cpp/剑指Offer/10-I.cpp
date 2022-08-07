// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了94.63% 的用户

class Solution {
public:
    
    int fib(int n) {
        unsigned long long table[101] = {0};
        table[0] = 0;
        table[1] = 1;

        for (int i = 2; i <= n; ++i) {
            table[i] = (table[i-1] + table[i-2]) % 1000000007;
        } 
        return table[n];
    }
};