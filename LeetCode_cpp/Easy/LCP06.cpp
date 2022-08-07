class Solution {
public:
    int minCount(vector<int>& coins) {
        int n = coins.size(), ans = 0;
        
        for ( int i = 0; i < n; ++i ) {
            ans += (coins[i] / 2) + (coins[i] % 2);
        }
        
        return ans;
    }
};