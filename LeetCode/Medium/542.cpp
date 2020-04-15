// 执行用时 :408 ms, 在所有 C++ 提交中击败了7.40% 的用户
// 内存消耗 :64.7 MB, 在所有 C++ 提交中击败了33.33%的用户

class Solution {
private:
    static constexpr int _direct_x[4] = { -1, 0, 1, 0 }, _direct_y[4] = { 0, 1, 0, -1 };

    typedef struct _entry {
        int x, y, steps;
        _entry( int ax, int ay, int asteps) :x(ax), y(ay), steps(asteps) {}
    } _entry;


public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = ( m == 0 ) ? 0 : matrix[0].size();
        vector< vector<int> > ans( m, vector<int>(n, 0) );
        if ( m == 0 || n == 0 ) { return ans; }

        queue<_entry> q;
        vector< vector<bool> > vis;

        for ( int i = 0; i < m; ++i ) {
            for ( int j = 0; j < n; ++j ) {

                if ( matrix[i][j] ) {
                    vis.resize( m, vector<bool>(n, false) );
                    q.push( _entry(i, j, 0) );
                    vis[i][j] = true;
                    ans[i][j] = INT_MAX;

                    while ( !q.empty() ) {
                        int x = q.front().x, y = q.front().y, steps = q.front().steps;
                        q.pop();
                        
                        if ( !matrix[x][y] ) { ans[i][j] = min( ans[i][j], steps ); }
                        if ( steps+1 >= ans[i][j] ) { continue; }

                        for ( int i = 0; i < 4; ++i ) {
                            int nextx = x + _direct_x[i], nexty = y + _direct_y[i];
                            if ( nextx >= 0 and nextx < m and nexty >= 0 and nexty < n ) {
                                vis[nextx][nexty] = true;
                                q.push( _entry(nextx, nexty, steps+1) );
                            }
                        }
                    }
                }

            }
        }

        return ans;
    }
};