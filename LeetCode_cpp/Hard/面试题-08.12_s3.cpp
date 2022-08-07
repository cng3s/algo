// 显示用时 :4 ms, 在所有 C++ 提交中击败了97.99% 的用户
// 内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
private:
    vector<int> _queen_pos;
    int _n;

    bool _is_ok( int y, int x ) {
        for ( int i = 0; i < _queen_pos.size(); ++i ) {
            if ( x == _queen_pos[i] || abs(y-i) == abs(x-_queen_pos[i]) ) { return false; }
        }
        return true;
    }

    void _dfs( vector<vector<string>>& res, vector<string>& ans, int row ) {
        if ( row == _n ) {
            res.push_back( ans );
            return;
        }

        for ( int i = 0; i < _n; ++i ) {
            if ( _is_ok( row, i ) ) {
                ans[row][i] = 'Q';
                _queen_pos.push_back( i );
                _dfs( res, ans, row+1 );
                _queen_pos.pop_back( );
                ans[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ans(n, string(n, '.'));
        _n = n;
        _dfs( res, ans, 0 );
        return res;
    }
};