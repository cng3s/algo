// 执行用时：16 ms, 在所有 C++ 提交中击败了95.92% 的用户
// 内存消耗：17.3 MB, 在所有 C++ 提交中击败了65.05% 的用户
class Solution {
public:
    int candy(vector<int>& ratings) {
        int nratings = ratings.size();
        if (nratings == 0) { return 0; }

        vector<int> candys(nratings, 1);
        for (int i = 0; i < nratings-1; ++i) {
            if (ratings[i+1] > ratings[i]) { candys[i+1] = candys[i] + 1; }
        }

        for (int i = nratings-1; i > 0; --i) {
            if (ratings[i-1] > ratings[i] && candys[i-1] <= candys[i]) { candys[i-1] = candys[i] + 1; }
        }
        return accumulate(candys.cbegin(), candys.cend(), 0);
    }
};