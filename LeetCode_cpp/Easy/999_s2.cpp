// 执行用时 :4 ms, 在所有 C++ 提交中击败了58.90% 的用户
// 内存消耗 :6.2 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int stepX[4] = { 0, 1, 0, -1 }, stepY[4] = { 1, 0, -1, 0 };
        int Ry, Rx;
        for (Ry = 0; Ry < 8; ++Ry) {
            for (Rx = 0; Rx < 8; ++Rx) {
                if (board[Ry][Rx] == 'R')
                    goto out;
            }
        }

        out:
        int cnt = 0;

        for (int i = 0; i < 4; ++i) {
            for (int step = 1; ; ++step) {
                int curx = Rx + step*stepX[i], cury = Ry + step*stepY[i];
                if (curx < 0 || curx > 7 || cury < 0 || cury > 7 || board[cury][curx] == 'B')   { break; }
                if (board[cury][curx] == 'p') {
                    ++cnt;
                    break;
                }
            }
        }

        return cnt;
    }
};