// 斐波那契数列动态规划实现
// 有两种思路：
// 一种是pull方法 - 我从哪里来？
// 另一种是push方法 - 我要到哪里去？
//

#include <iostream>
using namespace std;

#define MAXN 10001

unsigned long long dp_pull[MAXN] = { 0 };
unsigned long long fib_pull( int n ) {
    if ( n < 0 ) { return 0; }
    if ( n == 1 || n == 0 ) { return n; }
    if ( dp_pull[n] == 0 ) { dp_pull[n] = fib_pull( n-1 ) + fib_pull( n-2 ); }
    return dp_pull[n];
}

unsigned long long dp_push[MAXN] = { 0, 1 };
int maxidx = 1; // 保存dp_push最大的元素索引
unsigned long long fib_push( int n ) {
    if ( maxidx >= n ) { return dp_push[n]; }
    int ans = dp_push[maxidx];
    for ( int i = maxidx+1; i <= n; ++i ) {
        dp_push[i] = dp_push[i-1] + dp_push[i-2];
    }
    maxidx = n;
    return dp_push[n];
}

int main() {
    int n;

    for ( int i = 0; i < 15; ++i ) {
        cout << fib_pull( i ) << " ";
        if ( i % 7 == 0 ) { cout << endl; }
    }
    for ( int i = 0; i < 15; ++i ) {
        cout << fib_push( i ) << " ";
        if ( i % 7 == 0 ) { cout << endl; }
    }

    return 0;
}