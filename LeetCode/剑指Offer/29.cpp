// 执行用时：16 ms, 在所有 C++ 提交中击败了25.02% 的用户
// 内存消耗：9.2 MB, 在所有 C++ 提交中击败了96.46% 的用户

class Solution {
    static constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) { return {}; }

        int nMatRow = matrix.size(), nMatCol = matrix[0].size(), total = nMatRow * nMatCol;
        int directionsIx = 0, row = 0, col = 0;
        vector<vector<bool>> vis(nMatRow, vector<bool>(nMatCol));
        vector<int> ans(nMatRow * nMatCol);

        for (int i = 0; i < total; ++i) {
            ans[i] = matrix[row][col];
            vis[row][col] = true;

            int nextRow = row + directions[directionsIx][0], nextCol = col + directions[directionsIx][1];
            if (nextRow < 0 || nextRow >= nMatRow || nextCol < 0 || nextCol >= nMatCol || vis[nextRow][nextCol]) {
                directionsIx = (directionsIx + 1) % 4;
            }

            row += directions[directionsIx][0];
            col += directions[directionsIx][1];
        }

        return ans;
    }
};