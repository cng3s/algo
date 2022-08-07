// 执行用时：4 ms, 在所有 C++ 提交中击败了92.48% 的用户
// 内存消耗：12.4 MB, 在所有 C++ 提交中击败了84.17% 的用户

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int minPrice = prices[0], ans = 0;
        for (int price : prices) {
            ans = max(ans, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return ans;
    }
};