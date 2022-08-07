#include <bits/stdc++.h>
using namespace std;

int main()   
{
    unsigned long n, m, target;
    
    while (cin >> target) {
        m = sqrt(target);
        for (n = 2; n <= m; ++n) {
            while (target % n == 0) {
                cout << n << ' ';
                target /= n;
            }
            m = sqrt(target);
        }
        
        if (target > 1)
            cout << target << ' ';
    }
}