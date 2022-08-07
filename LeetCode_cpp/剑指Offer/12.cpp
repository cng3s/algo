// 执行用时：16 ms, 在所有 C++ 提交中击败了98.51% 的用户
// 内存消耗：7.5 MB, 在所有 C++ 提交中击败了93.09% 的用户

class Solution {
private:
    bool vis[201][201];

    bool dfs(const vector<vector<char>>& board, const string& word, int x, int y, int wordIx) {
        if (wordIx == word.size() - 1 && board[y][x] == word[wordIx]) { return true; }
        if (x >= board[0].size() || y >= board.size()) { return false; }

        //cout << y << ", " << x << ", " << board[y][x] << endl;

        bool flag = false; 
        vis[y][x] = true;
        if (!vis[y][x+1] && x < board[0].size() - 1 && board[y][x+1] == word[wordIx+1]) { flag = dfs(board, word, x+1, y, wordIx+1); }
        if (!flag && y > 0 && !vis[y-1][x] && board[y-1][x] == word[wordIx+1]) { flag = dfs(board, word, x, y-1, wordIx+1); }
        if (!flag && y < board.size() - 1  && !vis[y+1][x] && board[y+1][x] == word[wordIx+1]) { flag = dfs(board, word, x, y+1, wordIx+1); }
        if (!flag && x > 0 && !vis[y][x-1] && board[y][x-1] == word[wordIx+1]) { flag = dfs(board, word, x-1, y, wordIx+1); }
        vis[y][x] = false;
        return flag;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0 || word.size() == 0) { return false; }
        memset(vis, 0, sizeof(vis));
        
        int nboard = board.size(), nsubBoard = board[0].size();
        for (int i = 0; i < nboard; ++i) {
            for (int j = 0; j < nsubBoard; ++j) {
                bool flag = false;
                //cout << board[i][j]<< ", " <<word[0] << endl;
                if (board[i][j] == word[0])
                    flag = dfs(board, word, j, i, 0);
                if (flag)
                    return true;
            }
        }
        return false;
    }
};