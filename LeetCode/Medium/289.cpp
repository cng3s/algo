// 执行用时 :4 ms, 在所有 C++ 提交中击败了66.13% 的用户
// 内存消耗 :7.1 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
private:
    int _M, _N;
    static constexpr int 
        _direct_y[8] = { 0, -1, 0, 1, -1, -1, 1, 1 },
        _direct_x[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
    

public:
    void gameOfLife(vector<vector<int>>& board) {
        
        _M = board.size(), _N = board[0].size();

        vector<vector<int>> origin_board = board;

        for ( int i = 0; i < _M; ++i ) {
            for ( int j = 0; j < _N; ++j ) {
                
                // count neighbor cells who is living
                int neighbors = 0;
                for ( int k = 0; k < 8; ++k ){
                    int neighbory = i + _direct_y[k], neighborx = j + _direct_x[k];
                    if ( neighbory < 0 || neighbory >= _M || neighborx < 0 || neighborx >= _N ) { continue; }
                    if ( origin_board[neighbory][neighborx] ) { ++neighbors; }
                }

                // do something
                if ( origin_board[i][j] ) { // if current cell is living
                    if ( neighbors < 2 || neighbors > 3 ) { board[i][j] = 0; }
                } else { // current cell is dead
                    if ( neighbors == 3 ) { board[i][j] = 1; }
                }

            }
        }
    }
};