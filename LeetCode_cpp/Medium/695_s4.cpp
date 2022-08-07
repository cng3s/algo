class Solution {
private:
    int _dfs(vector<vector<int>>& grid, int y, int x) {
        if (y < 0 || x < 0 || y == grid.size() || x == grid[y].size() || !grid[y][x]) {
            return 0;
        }
        grid[y][x] = 0;
        return _dfs(grid, y, x+1) + _dfs(grid, y, x-1) + _dfs(grid, y-1, x) + _dfs(grid, y+1, x) + 1;
    }


public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    maxSize = max(_dfs(grid, i, j), maxSize);
                }
            }
        }
        return maxSize;
    }
};