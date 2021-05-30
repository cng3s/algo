// 执行用时：8 ms, 在所有 C++ 提交中击败了99.70% 的用户
// 内存消耗：19.7 MB, 在所有 C++ 提交中击败了78.72% 的用户

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;

        for (int i = 0; i < m; ++i) {
            if (flowerbed[i] == 1) {
                if (prev < 0) { count += i / 2; }
                else { count += (i - prev - 2) / 2; }
                if (count >= n) { return true; }
                prev = i;
            }
        }
        if (prev < 0) { count += (m + 1) / 2; }
        else { count += (m - prev - 1) / 2; }
        return count >= n;
    }
};