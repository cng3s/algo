class Solution {
private:
    void gen_str( string& ans, queue<char>& q1, queue<char>& q2 ) {
        while ( !q1.empty() ) {
            ans.push_back( q1.front() );
            ans.push_back( q2.front() );
            q1.pop();
            q2.pop();
        }
    }
    
public:
    string reformat(string s) {
        int n = s.size();
        queue<char> alpha;
        queue<char> num;
        
        
        for ( int i = 0; i < n; ++i ) {
            if ( isalpha(s[i]) )    { alpha.push(s[i]); }
            else                    { num.push(s[i]); }
        }
        
        string ans = "";
        int asz = alpha.size(), nsz = num.size();
        if ( asz == nsz or asz+1 == nsz or asz == nsz+1 ) {
            if ( asz+1 == nsz )     { 
                ans.push_back(num.front());
                num.pop();
                gen_str( ans, alpha, num );
            }
            else if ( asz == nsz+1 ) {
                ans.push_back(alpha.front());
                alpha.pop();
                gen_str( ans, num, alpha );
            }
            else {
                gen_str( ans, num, alpha );
            }
        }
        
        return ans;
    }
};