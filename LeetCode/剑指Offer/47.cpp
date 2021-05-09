// 执行用时：8 ms, 在所有 C++ 提交中击败了81.80% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了41.05% 的用户

class Solution {
private:
    int table[201][201];

    int dfs(const vector<vector<int>>& grid, int x, int y) {
        if (y >= grid.size() || x >= grid[0].size()) { return 0; }
        if (table[y][x] != 0) { return table[y][x]; }

        int res = max(dfs(grid, x+1, y), dfs(grid, x, y+1)) + grid[y][x];
        table[y][x] = res;
        return res;
    }
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) { return 0; }
        memset(table, 0, sizeof(table));
        return dfs(grid, 0, 0);
    }
};