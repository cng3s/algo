// 《算法笔记》 - P427
// 数塔问题 - 采用DP的pull式和push式写法
//

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 101

typedef long long ll;
ll pyramid[MAXN][MAXN] = { 0 };
ll dp_push[MAXN][MAXN] = { 0 };
ll dp_pull[MAXN][MAXN] = { 0 };
int n;

static ll _init_dp_push( int y, int x ) {
    if ( dp_push[y][x] == 0 ) {
        dp_push[y][x] = max( _init_dp_push( y+1, x ) , _init_dp_push( y+1, x+1 ) ) + pyramid[y][x];
    }
    return dp_push[y][x];
}

void init_dp_push() {
    for ( int i = 0; i < n; ++i ) {
        dp_push[n-1][i] = pyramid[n-1][i];
    }

    _init_dp_push( 0, 0 );
}

void init_dp_pull() {
    for ( int i = 0; i < n; ++i ) {
        dp_pull[n-1][i] = pyramid[n-1][i];
    }

 
    for ( int i = n-2; i >= 0; --i ) {
        for ( int j = 0; j <= i; ++j )
            dp_pull[i][j] = max( dp_pull[i+1][j], dp_pull[i+1][j+1] ) + pyramid[i][j];
    }
}

void print_dp( ll dp[][101] ) {
    cout << "print_dp" << endl;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j <= i; ++j )
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> n;

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j <= i; ++j )
            cin >> pyramid[i][j];
    }

    init_dp_push();
    init_dp_pull();

    print_dp( dp_push );
    print_dp( dp_pull );

    return 0;
}
