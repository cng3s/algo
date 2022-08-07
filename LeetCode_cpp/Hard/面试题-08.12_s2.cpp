// 执行用时 :12 ms, 在所有 C++ 提交中击败了52.51% 的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
//
// 解法并没有什么区别，只是在_is_ok函数做了一个优化操作
// 直接判断所有已放置的皇后与当前皇后是否冲突，减少了遍历棋盘判断的傻逼逻辑
//
class Solution {
private:
    enum { EMPTY, QUEEN };
    vector<int> _queens_pos;

    int _n;

    bool _is_ok( vector<vector<int>>& board, int y, int x ) {
        for ( int i = 0; i < _queens_pos.size(); ++i ) {
            if ( _queens_pos[i] == x || abs(i-y) == abs(_queens_pos[i]-x) )
                return false;
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
            
            bool success = _is_ok(board, row, i);
            if ( success ) {
                board[row][i] = QUEEN;
                _queens_pos.push_back( i );
                _dfs(board, row+1, res);
                _queens_pos.pop_back();
                board[row][i] = EMPTY;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> res;
        _n = n;

        vector<vector<int>> board(n, vector<int>(n, EMPTY) );

        for ( int i = 0; i < n; ++i ) {
            
            // 生成解法和相应的棋局
            board[0][i] = QUEEN;
            _queens_pos.push_back( i );
            _dfs(board, 1, res);
            _queens_pos.pop_back();
            board[0][i] = EMPTY;

        }

        return res;
    }
};