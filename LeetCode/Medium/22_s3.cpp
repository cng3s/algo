// bfs
// 和s1性能相同
//

class Solution {
private:
    string _s;
    int _n, _left;
    void _dfs( vector<string>& ans ) {
        if ( _left == _n && _s.size() / 2 == _n ) {
            //cout << _s << endl;
            ans.push_back( _s );
            return;
        }

        if ( _left > (_s.size() - _left) ) {
            _s.push_back( ')' );
            _dfs( ans );
            _s.pop_back();
        }

        if ( _left < _n ) {
            _s.push_back( '(' );
            ++_left;
            _dfs( ans );
            _s.pop_back();
            --_left;
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        _n = n;
        _left = 1;
        _s.push_back( '(' );
        _dfs( ans );
        return ans;
    }
};