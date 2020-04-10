// 执行用时 :12 ms, 在所有 C++ 提交中击败了57.06% 的用户
// 内存消耗 :9 MB, 在所有 C++ 提交中击败了100.00%的用户
// 时间复杂度：O(n)，空间复杂度：O(n)
//

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int idx = 0;
        string ans = "";
        for ( int i = 0; i < s.size(); ) {
            if ( i < s.size() && s[i] != ' ' ) {
                words.push_back( string("") );
                while ( i < s.size() && s[i] != ' ' ) { words[idx].push_back( s[i++] ); }
                ++idx;
            }
            while ( i < s.size() && s[i] == ' ' ) { ++i; }
        }
        
        if ( !words.empty() ) {
            auto it = words.rbegin();
            ans.append( *it );
            for ( ++it; it != words.rend(); ++it ) {
                ans.push_back( ' ' );
                ans.append( *it );
            }
        }
        
        return ans;
    }
};