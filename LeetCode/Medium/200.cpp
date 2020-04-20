// 执行用时 :16 ms, 在所有 C++ 提交中击败了57.67% 的用户
// 内存消耗 :9.1 MB, 在所有 C++ 提交中击败了100.00%的用户
// BFS
//
class Solution {
private:
    static constexpr int _direct[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = (n == 0 ? 0 : grid[0].size());
        if ( n == 0 or m == 0 ) { return 0; }
        vector<vector<bool>> vis( n, vector<bool>(m, false) );
        queue<pair<int, int>> q;

        int ans = 0;
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( grid[i][j] == '1' and !vis[i][j] ) {
                    q.emplace( i, j );
                    vis[i][j] = true;
                    ++ans;

                    while ( !q.empty() ) {
                        auto [y, x] = q.front();
                        q.pop();
                        for ( int k = 0; k < 4; ++k ) {
                            int nextx = x+_direct[k][0], nexty = y+_direct[k][1];
                            if ( nextx >= 0 and nextx < m and nexty >= 0 and nexty < n and
                                 grid[nexty][nextx] == '1' and !vis[nexty][nextx] ) {
                                
                                q.emplace( nexty, nextx );
                                vis[nexty][nextx] = true;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};