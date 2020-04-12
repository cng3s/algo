class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P( m );
        vector<int> ans;
        for ( int i = 1; i <= m; ++i ) { P[i-1] = i; }
        
        for ( auto key : queries ) {
            int idx;
            for ( int i = 0; i < m; ++i ) { if (P[i] == key ) { idx = i; break; } }
            ans.push_back( idx );
            int val = P[idx];
            for ( int i = idx; i >= 1; --i ) { P[i] = P[i-1]; }
            P[0] = val;
        }
        return ans;   
    }
};