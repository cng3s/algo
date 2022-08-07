#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, cnt = 0;
    while (cin >> n) {
        cnt = 0;
        if (n == 0)
            break;
        
        while (n >= 2) {
            n += 1;
            cnt += n / 3; // 喝到的饮料
            n = n / 3 + n % 3 - 1; // 下一次的空瓶数量(不算上借的)
        }
        
        cout << cnt << '\n';
    }
    
    
    return 0;
}