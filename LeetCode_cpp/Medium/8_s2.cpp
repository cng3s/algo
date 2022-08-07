// 执行用时 :4 ms, 在所有 C++ 提交中击败了85.86% 的用户
// 内存消耗 :6.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int myAtoi(string str) {
        
        long ans = 0, base = 1;
        int idx = 0, left = 0;
        
        while ( str[idx] == ' ' ) { ++idx; }

        if ( str[idx] == '+' ) { ++idx; }
        else if ( str[idx] == '-') { base = -1; ++idx; }
        
        if ( isdigit(str[idx]) ) {

            for ( ; idx < str.size() && isdigit(str[idx]); ++idx ) {
                
                ans = ans*10 + long((str[idx])-'0')*base;
                if ( ans > INT_MAX ) { ans = INT_MAX; break; }
                else if ( ans < INT_MIN ) { ans = INT_MIN; break; }
            }
        }
        return int(ans);
    }
};