// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
// pull式动态规划做法 - 我从哪里来？
//

class Solution {
private:
typedef unsigned long long _ull;

    _ull _dp[31];

public:

    Solution() {
        fill( _dp, _dp+31, 0 );
        _dp[1] = 1;
    }

    int fib(int N) {
        if ( _dp[N] != 0 ) { return _dp[N]; }
        if ( N == 0 || N == 1 ) { return N; }
        _dp[N] = fib( N-1 ) + fib( N-2 );
        return _dp[N];
    }
};