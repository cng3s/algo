// 执行用时：28 ms, 在所有 C++ 提交中击败了14.93% 的用户
// 内存消耗：19.7 MB, 在所有 C++ 提交中击败了78.13% 的用户

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) { return true; }
        int nflowerbed = flowerbed.size();
        if (nflowerbed == 1) { return n == 1 && flowerbed[0] == 0; }
        if (n > 0 && flowerbed[0] == 0 && flowerbed[1] == 0) { flowerbed[0] = 1; --n; }
        if (n > 0 && flowerbed[nflowerbed-1] == 0 && flowerbed[nflowerbed-2] == 0) { flowerbed[nflowerbed-1] = 1; --n; }

        for (int i = 2 ; i < nflowerbed - 1 && n > 0 ; ++i) {
            if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) { flowerbed[i] = 1; --n; }
        }

        return n == 0;
    }
};