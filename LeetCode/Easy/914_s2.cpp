// 执行用时 :32 ms, 在所有 C++ 提交中击败了10.74% 的用户
// 内存消耗 :16.6 MB, 在所有 C++ 提交中击败了5.71%的用户
// 注：这种解法效率和s1一摸一样的。
// 提升的原因主要因为std::ios::sync_with_stdio(false);
// 所以是IO效率的提升

class Solution {
private:
    int _gcd(int x, int y) {
        return x == 0 ? y : _gcd(y%x, x);
    }

public:
    bool hasGroupsSizeX(vector<int>& deck) {
        std::ios::sync_with_stdio(false);
        int card_cnt[10001] = { 0 };

        for (auto it : deck) {
            ++card_cnt[it];
        }

        int g = -1;
        for (auto it : card_cnt) {
            g = g < 0 ? it : _gcd(g, it);
            if (g == 1) {
                return false;
            }
        }
        return g >= 2;
    }
};