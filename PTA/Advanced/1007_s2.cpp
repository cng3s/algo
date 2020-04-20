#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 10010
int dp[MAXN], A[MAXN], beg[MAXN]={0};


int main() {
    int n;
    bool all_above0 = false;
    scanf("%d", &n);

    for ( int i = 0; i < n; ++i )   {
        scanf("%d", &A[i]);
        if ( A[i] >= 0 )    all_above0 = true;    
    }

    if ( !all_above0 ) {
        printf("0 %d %d", A[0], A[n-1]);
        return 0;
    }

    dp[0] = A[0];
    int ansidx = 0;
    for ( int i = 1; i < n; ++i ) {
        if ( dp[i-1]+A[i] > A[i] ) {
            dp[i] = dp[i-1]+A[i];
            beg[i] = beg[i-1];
        } else {
            dp[i] = A[i];
            beg[i] = i;
        }
        if ( dp[i] > dp[ansidx] )   ansidx = i;
    }

    printf("%d %d %d", dp[ansidx], A[beg[ansidx]], A[ansidx]);

    return 0;
}