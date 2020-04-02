// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户


class Solution {
private:
    int _M, _N;
    static constexpr int 
        _direct_y[8] = { 0, -1, 0, 1, -1, -1, 1, 1 },
        _direct_x[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
    

public:
    void gameOfLife(vector<vector<int>>& board) {
        
        _M = board.size(), _N = board[0].size();

        vector<pair<int, int>> change_pos; 

        for ( int i = 0; i < _M; ++i ) {
            for ( int j = 0; j < _N; ++j ) {
                
                // count neighbor cells who is living
                int neighbors = 0;
                for ( int k = 0; k < 8; ++k ){
                    int neighbory = i + _direct_y[k], neighborx = j + _direct_x[k];
                    if ( neighbory < 0 || neighbory >= _M || neighborx < 0 || neighborx >= _N ) { continue; }
                    if ( board[neighbory][neighborx] ) { ++neighbors; }
                }

                // do something
                if ( (board[i][j] && (neighbors<2 || neighbors>3)) ||
                     (!board[i][j] && neighbors == 3) ) {
                    change_pos.push_back( {i, j} );
                }
            }
        }
        for ( auto it : change_pos ) {
            int y = it.first, x = it.second;
            board[y][x] = !board[y][x];
        }
    }
};