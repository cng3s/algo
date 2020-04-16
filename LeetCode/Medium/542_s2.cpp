// 执行用时 :256 ms, 在所有 C++ 提交中击败了18.20% 的用户
// 内存消耗 :27.6 MB, 在所有 C++ 提交中击败了66.67%的用户
// 从一个 **超级0** 找1的BFS解法，效率比原版的快的多。
// 如果不理解这中解法，就看LeetCode官方题解
// 本质上说，就是把 多点找多点 的问题转换成了 单点找多点的问题
// 而这个单点，就是 **超级0**
// 这种解法 设置 **超级1** 寻找0则不行，因为vis会有阻碍
//
//

class Solution {
private:
    static constexpr int _direct[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = ( n == 0 ? 0 : matrix[0].size() );
        vector<vector<int>> ans( n, vector<int>(m, 0) );

        if ( n == 0 || m == 0 ) { return ans; }

        vector<vector<bool>> vis( n, vector<bool>(m, false) );
        queue<pair<int, int>> q;

        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j )
                if ( matrix[i][j] == 0 ) {
                    q.emplace( i, j );
                    vis[i][j] = true;
                }
        }

        while ( !q.empty() ) {
            auto [y, x] = q.front();
            q.pop();

            for ( int i = 0; i < 4; ++i ) {
                int nextx = x + _direct[i][0], nexty = y + _direct[i][1];
                if ( nextx >= 0 and nextx < m and nexty >= 0 and nexty < n and !vis[nexty][nextx]) {
                    vis[nexty][nextx] = true;
                    ans[nexty][nextx] = ans[y][x] + 1;
                    q.emplace( nexty, nextx );
                }
            }
        }

        return ans;
    }
};