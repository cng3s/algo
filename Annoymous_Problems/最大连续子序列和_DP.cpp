// 《算法笔记》 P430
//

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1001

int A[MAXN], dp[MAXN] = { 0 }, n, maxidx_push, maxidx_pull;

void dp_push() {
    for ( int i = 1; i < n; ++i ) {
        dp[i] = max( A[i], A[i]+dp[i-1] );
        if ( dp[i] > dp[maxidx_push] ) { maxidx_push = i; }
    }
}

int dp_pull( int idx ) {
    if ( dp[idx] != INT_MIN ) { return dp[idx]; }
    dp[idx] = max( A[idx], A[idx]+dp_pull(idx-1) );
    if ( dp[idx] > dp[maxidx_pull] ) { maxidx_pull = idx; }
    return dp[idx];
}

int main() {
    cin >> n;

    for ( int i = 0; i < n; ++i ) { cin >> A[i]; }

    dp_push();
    cout << dp[maxidx_push] << endl;

    fill( dp, dp+MAXN, INT_MIN );
    dp[0] = A[0];
    dp_pull( n );
    cout << dp[maxidx_pull] << endl;


    return 0;
}