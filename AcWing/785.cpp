#include <iostream>
using namespace std;

const int maxn = 1e6 + 10;
int q[maxn], n;

void qsort( int q[], int lo, int hi )
{
    if ( lo >= hi ) return;

    int x = q[lo], l = lo-1, r = hi+1;
    while ( l < r ) {
        do l++; while ( q[l] < x );
        do r--; while ( q[r] > x );
        if ( l < r ) swap( q[l], q[r] );
    }

    qsort( q, lo, r );
    qsort( q, r+1, hi );
}

int main()
{
    scanf("%d", &n);

    for ( int i = 0; i < n; ++i ) { scanf("%d", &q[i]); }
    qsort( q, 0, n-1 );
    for ( int i = 0; i < n; ++i ) { printf("%d ", q[i]); }

    return 0;
}