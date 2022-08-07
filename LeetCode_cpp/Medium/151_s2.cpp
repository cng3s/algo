// 执行用时 :8 ms, 在所有 C++ 提交中击败了85.79% 的用户
// 内存消耗 :7.3 MB, 在所有 C++ 提交中击败了100.00%的用户
// 原地翻转，时间复杂度O(n)，空间复杂度O(1)
//

class Solution {
public:
    string reverseWords(string s) {

        reverse( s.begin(), s.end() );

        int idx = 0;
        for ( int i = 0; i < s.size(); ++i ) {
            if ( s[i] != ' ' ) {
                if ( idx != 0 ) { s[idx++] = ' '; }
                int end = idx;
                while ( i < s.size() && s[i] != ' ' ) { s[end++] = s[i++]; }
                reverse( s.begin()+idx, s.begin()+end );
                idx = end;
            }
        }

        s.erase( s.begin()+idx, s.end() );
        return s;
    }
};