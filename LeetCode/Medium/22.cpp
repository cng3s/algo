// 执行用时 :4 ms, 在所有 C++ 提交中击败了89.93% 的用户
// 内存消耗 :11.7 MB, 在所有 C++ 提交中击败了87.66%的用户
// dfs
//

class Solution {
private:
    stack<char> _left;
    string _s;
    int _n;
    void _dfs( vector<string>& ans ) {
        if ( _left.size() == _n && _s.size() == 2*_n ) {
            //cout << _s << endl;
            ans.push_back( _s );
            return;
        }

        if ( _left.size() > (_s.size() - _left.size()) ) {
            _s.push_back( ')' );
            _dfs( ans );
            _s.pop_back();
        }

        if ( _left.size() < _n ) {
            _s.push_back( '(' );
            _left.push( '(' );
            _dfs( ans );
            _s.pop_back();
            _left.pop();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        _n = n;
        _left.push( '(' );
        _s.push_back( '(' );
        _dfs( ans );
        return ans;
    }
};