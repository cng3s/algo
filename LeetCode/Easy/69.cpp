class Solution {
public:
    int mySqrt(int x) {
        int ans;
        for ( unsigned long long i = 0; ; ++i ) {
            unsigned long long res = i*i;
            if ( res > x ) break;
            if ( res == x ) { return i; }
            else ans = i;
        }
        return ans;
    }
};