// 执行用时 :1716 ms, 在所有 C++ 提交中击败了5.12% 的用户
// 内存消耗 :252.2 MB, 在所有 C++ 提交中击败了6.25%的用户
// 最朴素的BFS做法
// 因为如果图特别大并且全是海洋（很少陆地），那么就非常地慢
// 改进方法就是 使用动态规划（其实就是打表，记录每个位置到陆地的最短距离）
// 然后不同的位置可以利用这个表进行剪枝操作
class Solution {
private:
    typedef struct _coord {
        int y, x, steps;
        _coord( int y1, int x1, int steps1 ) : y( y1 ), x( x1 ), steps( steps1 ) {}
    } _coord;

    static constexpr int direct_x[4] = { -1, 0, 1, 0 }, direct_y[4] = { 0, 1, 0, -1 };
#define MAXN 101
    int N;
    vector<vector<int>> grid;
    bool vis[MAXN][MAXN];

    int _bfs( int y, int x ) {
        memset( vis, false, sizeof vis );
        queue<_coord> q;
        q.push( {y, x, 0} );
        vis[y][x] = true;

        while ( !q.empty() ) {
            _coord c = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextx = c.x + direct_x[i], nexty = c.y + direct_y[i];
                if ( nextx < 0 || nextx >= N || nexty < 0 || nexty >= N || vis[nexty][nextx] ) { continue; }
                vis[nexty][nextx] = 1;
                if ( grid[nexty][nextx] ) { return c.steps + 1; }
                q.push( {nexty, nextx, c.steps+1} );
            }
        }
        return -1;
    }

public:
    int maxDistance(vector<vector<int>>& grid) {
        N = grid.size();
        int res = -1;
        this->grid = grid;

        for ( int i = 0; i < N; ++i ) {
            for ( int j = 0; j < N; ++j )
                if ( !grid[i][j] )
                    res = max( res, _bfs(i, j) );
        }
        return res;
    }
};