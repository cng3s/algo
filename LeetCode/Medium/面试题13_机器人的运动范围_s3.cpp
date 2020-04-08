// 执行用时 :4 ms, 在所有 C++ 提交中击败了81.36% 的用户
// 内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
private:
    static constexpr int _direct_x[2] = { 0, 1 }, _direct_y[2] = { 1, 0 };

    int _get( int n ) {
        int sum = 0;
        while ( n ) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int movingCount(int m, int n, int k) {
        int ans = 1;
        vector<vector<bool>> vis( m, vector<bool>( n, false ) );
        queue<pair<int, int>> q;
        q.push( {0, 0} );
        vis[0][0] = true;

        while ( !q.empty() ) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for ( int i = 0; i < 2; ++i ) {
                int nextx = x + _direct_x[i], nexty = y + _direct_y[i];
                if ( nexty < 0 || nexty >= m || nextx < 0 || nextx >= n || vis[nexty][nextx] || _get(nexty) + _get(nextx) > k ) { continue; }
                q.push( { nextx, nexty } );
                vis[nexty][nextx] = true;
                ++ans;
            }
        }
        return ans;
    }
};