// 双100%

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int Ry, Rx;
        for (Ry = 0; Ry < 8; ++Ry) {
            for (Rx = 0; Rx < 8; ++Rx) {
                if (board[Ry][Rx] == 'R')
                    goto out;
            }
        }

        out:
        int cnt = 0;
        for (int i = Ry+1; i < 8; ++i) {
            if (board[i][Rx] == 'p')                                { cnt += 1; break; }
            else if (board[i][Rx] == 'B'|| board[i][Rx] == 'R')     { break; }
        }
        for (int i = Ry-1; i >= 0; --i) {
            if (board[i][Rx] == 'p')                                { cnt +=1; break; }
            else if (board[i][Rx] == 'B' || board[i][Rx] == 'R')    { break; }
        }
        for (int i = Rx-1; i >= 0; --i) {
            if (board[Ry][i] == 'p')                                { cnt += 1; break; }
            else if (board[Ry][i] == 'B' || board[Ry][i] == 'R')    { break; }
        }
        for (int i = Rx+1; i < 8; ++i) {
            if (board[Ry][i] == 'p')                                { cnt += 1; break; }
            else if (board[Ry][i] == 'B' || board[Ry][i] == 'R')    { break; }
        }
        return cnt;
        
    }
};