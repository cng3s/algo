// 执行用时 :12 ms, 在所有 C++ 提交中击败了16.22% 的用户
// 内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
private:
    static constexpr int _direct_x[4] = { -1, 0, 1, 0 }, _direct_y[4] = { 0, 1, 0, -1 };
    int _m, _n, _k;
    vector<vector<bool>> vis;

    int _get_digits_sum( int n ) {
        int sum = 0;
        while ( n ) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    void _dfs( int y, int x, int& ans ) {
        if ( y >= _m || y < 0 || x >= _n || x < 0 || vis[y][x] ) { return; }
        vis[y][x] = true;
        int sum = _get_digits_sum(y) + _get_digits_sum(x);
        if ( sum > _k ) { return; }
        ++ans;
        for ( int i = 0; i < 4; ++i ) {
            int nexty = y + _direct_y[i], nextx = x + _direct_x[i];
            _dfs( nexty, nextx, ans );
        }
    }

public:
    int movingCount(int m, int n, int k) {
        _m = m, _n = n, _k = k;
        vis.resize( m, vector<bool>( n, false ) );
        int ans = 0;
        _dfs( 0, 0, ans );
        return ans;
    }
};