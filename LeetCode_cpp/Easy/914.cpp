// 执行用时 :48 ms, 在所有 C++ 提交中击败了6.73% 的用户
// 内存消耗 :16.7 MB, 在所有 C++ 提交中击败了5.71%的用户

class Solution {
private:
    int _gcd(int x, int y) {
        return x == 0 ? y : _gcd(y%x, x);
    }

public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> card_cnt;

        for (auto it : deck) {
            ++card_cnt[it];
        }

        int g = -1;
        for (auto it : card_cnt) {
            if (g < 0) {
                g = it.second;
            } else {
                g = _gcd(g, it.second);
                if (g == 1) {
                    return false;
                }
            }
        }
        return g >= 2;
    }
};