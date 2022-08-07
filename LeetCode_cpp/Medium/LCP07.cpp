class Solution {
private:
    int _dst, _k, _ans;
    
    unordered_map<int, vector<int>> _from_tos;
    
    void _dfs( int idx, int depth ) {
        
        if ( depth == _k )   { 
            if ( idx == _dst )  { ++_ans; }
            return;
        }
        
        auto it = _from_tos.find( idx );
        if ( it == _from_tos.end() )    { return; }
        vector<int> &l = it->second;
        
        for ( int i = 0; i < l.size(); ++i ) {
            _dfs( l[i], depth+1 );
        }
    }
    
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        _dst = n-1, _k = k, _ans = 0;
        int rsz = relation.size();
        
        if ( rsz == 0 )    return _ans;
        
        for ( int i = 0; i < rsz; ++i ) {
            auto it = _from_tos.find( relation[i][0] );
            if ( it == _from_tos.end() ) {
                _from_tos.emplace( relation[i][0], vector<int>{relation[i][1]}  );
            } else {
                it->second.emplace_back( relation[i][1] );
            }
        }
        
        _dfs( 0, 0 );
        
        return _ans;
    }
};