class Solution {
private:
#define maxn 1000005
#define mod 1000000007
    
    static constexpr int coin[4] = { 1, 5, 10, 25 };

public:
    int waysToChange(int n) {
        vector<int> dp( n+5, 0 );
        dp[0] = 1;

        for ( int i = 0; i < 4; ++i ) {
            int coins = coin[i];
            for ( int j = coins; j <= n; ++j )
                dp[j] = (dp[j]+dp[j-coins]) % mod;
        }

        return dp[n];
    }
};