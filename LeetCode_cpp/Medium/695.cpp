// 执行用时 :20 ms, 在所有 C++ 提交中击败了58.27% 的用户
// 内存消耗 :23.8 MB, 在所有 C++ 提交中击败了5.71%的用户

class Solution {
private:
    bool _visited[50][50];
    int _rows, _cols;

private:
    int _is_legal(vector<vector<int>>& grid, int y, int x) {
        return !(y >= _rows || x >= _cols || y < 0 || x < 0 || grid[y][x] == 0 || _visited[y][x]);
    }

    int _dfs(vector<vector<int>>& grid, int y, int x, int cnt) {
        _visited[y][x] = true;
        cnt += 1;
        if (_is_legal(grid, y+1, x)) {
            cnt = _dfs(grid, y+1, x, cnt);
        }
        if (_is_legal(grid, y-1, x)) {
            cnt = _dfs(grid, y-1, x, cnt);
        }
        if (_is_legal(grid, y, x+1)) {
            cnt = _dfs(grid, y, x+1, cnt);
        }
        if (_is_legal(grid, y, x-1)) {
            cnt = _dfs(grid, y, x-1, cnt);
        }
        return cnt;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(_visited, false, 50*50);
        int maxSize = 0;
        _rows = grid.size(), _cols = grid[0].size();
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                if (grid[i][j] == 1 && _visited[i][j] == false) {
                    int size = _dfs(grid, i, j, 0);
                    if (size > maxSize) {
                        maxSize = size;
                    }
                    cout << endl << endl;
                }
            }
        }
        return maxSize;
    }
};