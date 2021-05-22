// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了97.09% 的用户

class Solution {
public:
    int table[101][101];

    int dfs(int m, int n, int k, int x, int y) {
        if (x < 0 || y < 0 || y >= m || x >= n || table[y][x] == -1) { return 0; }
        if (table[y][x]) { return 0; }


        int sum = 0, tmpx = x, tmpy = y;
        while (tmpx != 0) { sum += tmpx % 10; tmpx /= 10; }
        while (tmpy != 0) { sum += tmpy % 10; tmpy /= 10; }

        if (sum > k) { table[y][x] = false; return 0; }
        //cout << y << ", " << x << ", " << "1\n";
        table[y][x] = 1;
        return dfs(m, n, k, x+1, y) + dfs(m, n, k, x-1, y) + dfs(m, n, k, x, y+1) + dfs(m, n, k, x, y-1) + 1;
    }

    int movingCount(int m, int n, int k) {
        memset(table, 0, sizeof table);
        return dfs(m, n, k, 0, 0);
    }
};