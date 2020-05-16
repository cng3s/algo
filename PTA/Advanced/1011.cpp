#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    double n[3];
    char bet[3];
    for ( int i = 0; i < 3; ++i ) {
        double arg1, arg2, arg3;
        scanf("%lf%lf%lf", &arg1, &arg2, &arg3);
        n[i] = max(arg1, arg2);
        n[i] = max(n[i], arg3);
        if ( n[i] == arg1 ) { bet[i] = 'W'; }
        else if ( n[i] == arg2 ) { bet[i] = 'T'; }
        else { bet[i] = 'L'; }
    }
    for ( int i = 0; i < 3; ++i ) { printf("%c ", bet[i]); }
    double res = (n[1]*n[2]*n[0]*0.65-1)*2;
    printf("%.2lf", res);

    return 0;
}