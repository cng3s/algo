// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
// push式的动态规划做法 --> 我要去哪里？
//

class Solution {
private:
typedef unsigned long long _ull;

    _ull _dp[31];
    int _maxidx;

public:
    Solution() : _maxidx(1) {
        fill( _dp, _dp+31, 0 );
        _dp[1] = 1;
    }

    int fib(int N) {
        if ( N <= _maxidx ) { return _dp[N]; }
        int ans = _dp[_maxidx];
        for ( int i = _maxidx+1; i <= N; ++i ) {
            _dp[i] = _dp[i-1] + _dp[i-2];
        }
        _maxidx = N;
        return _dp[N];
    }
};