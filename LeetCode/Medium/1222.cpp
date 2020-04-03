// 做了一个小优化，就是for ( auto it : queens )改为
// for ( const auto& it : queens )，速度有一定提升

// 执行用时 :4 ms, 在所有 C++ 提交中击败了89.81% 的用户
// 内存消耗 :11.1 MB, 在所有 C++ 提交中击败了6.67%的用户


class Solution {
private:
    enum { QUEEN, KING };
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        int board[8][8], ky = king[0], kx = king[1];
        vector<vector<int>> res;

        memset( board, -1, sizeof(int) * 64 );
        
        board[ky][kx] = KING;
        for ( auto it : queens ) {
            board[it[0]][it[1]] = QUEEN;
        }
        

        for ( auto it : queens ) {
            int qy = it[0], qx = it[1];
            
            // 在同一行、同一列或同一斜线上
            if ( qy == ky || qx == kx || abs(qy-ky) == abs(qx-kx) ) {
                int directy = qy == ky ? 0 : (qy > ky ? -1 : 1);
                int directx = qx == kx ? 0 : (qx > kx ? -1 : 1);

                for (int i = qx+directx, j = qy+directy; 
                    j >= 0 && j < 8 && i >= 0 && i < 8;
                    i += directx, j += directy) {

                    if ( board[j][i] == QUEEN ) { break; }
                    else if ( board[j][i] == KING ) {
                        vector<int> res1 = { qy, qx };
                        res.push_back( res1 );
                        break;
                    }
                }
            }
        }

        return res;
    }
};