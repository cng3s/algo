// 执行用时 :20 ms, 在所有 C++ 提交中击败了28.64% 的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
private:
    enum { EMPTY, QUEEN };

    static constexpr int _direct_y[8] = { 0, 1, 0, -1, -1, -1, 1, 1 },
                         _direct_x[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };

    int _n;

    bool _is_ok( vector<vector<int>>& board, int y, int x ) {
        
        for ( int i = 0; i < 8; ++i ) { // traverse array _direct_y and _direct_x
            for ( int j = 1; j < _n; ++j ) { // step length
                int nexty = y + j*_direct_y[i], nextx = x + j*_direct_x[i];
                if ( nexty < 0 || nexty >= _n || nextx < 0 || nextx >= _n ) { break; }
                if ( board[nexty][nextx] == QUEEN ) { return false; }
            }
        }
        return true;
    }

    // _dfs 返回 boards，即所有可行的棋盘布局
    void _dfs( vector<vector<int>>& board, int row, vector<vector<string>>& res ) {

        if ( row == _n ) {
            // 将类型为vector<vector<int>>,大小为 NxN 的棋盘转换为vector<string>类型的棋盘
            vector<string> str_board;
            for ( int i = 0; i < _n; ++i ) {
                string row = "";
                for ( int j = 0; j < _n; ++j ) {
                    row.push_back( board[i][j] == QUEEN ? 'Q' : '.' );
                }
                str_board.push_back( row );
            }
            res.push_back( str_board );
            return;
        }

        for ( int i = 0; i < _n; ++i ) {
            board[row][i] = QUEEN;
            bool success = _is_ok(board, row, i);
            if ( success ) {
                _dfs(board, row+1, res);
            }
            board[row][i] = EMPTY;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> res;
        _n = n;

        vector<vector<int>> board(n);
        for ( int j = 0; j < n; ++j ) {
            board[j].resize(n);
            fill( board[j].begin(), board[j].begin()+n, EMPTY );
        }

        for ( int i = 0; i < n; ++i ) {
            
            // 生成解法和相应的棋局
            cout << 0 << ", " << i << endl;
            board[0][i] = QUEEN;
            _dfs(board, 1, res);
            board[0][i] = EMPTY;

        }

        return res;
    }
};