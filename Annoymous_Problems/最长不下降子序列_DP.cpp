#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1001

int A[MAXN], dp[MAXN] = { INT_MIN }, n;

int dp_push() {
    int ans = 0;
    for ( int i = 0; i < n; ++i ) {
        dp[i] = 1;
        for ( int j = i-1; j >= 0; --j ) {
            if ( A[i] > A[j] ) { dp[i] = max( dp[i], dp[j]+1 ); }
        }
        ans = max( dp[i], ans );
    }
    return ans;
}

static int _pull( int idx, int& ans ) {
    if ( dp[idx] != INT_MIN ) { return dp[idx]; }
    dp[idx] = 1;
    for ( int j = idx-1; j >= 0; --j ) {
        if ( A[idx] > A[j] ) { dp[idx] = max( dp[idx], _pull( j, ans )+1 ); }
    }
    ans = max( dp[idx], ans );
    return dp[idx];
}

int dp_pull() {
    if ( n == 0 ) { return 0; } 
    int ans = 0;
    for ( int i = 0; i < n; ++i ) {
        _pull( i, ans );
    }
    return ans;
}

int main() {
    cin >> n;
    for ( int i = 0; i < n; ++i ) { cin >> A[i]; }
    
    cout << dp_push() << endl;
    fill( dp, dp+MAXN, INT_MIN );
    cout << dp_pull() << endl;

    return 0;
}