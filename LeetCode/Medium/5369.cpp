class Solution {
private:
    enum { SMALLER, BIGGER };
    
    void _dfs( vector<int>& unit, vector<int>& rating, int rating_cur, int& cnt, const int mark ) {
        if ( unit.size() + rating.size() - rating_cur < 3 ) { // 剪枝
            return;
        }
        if ( unit.size() == 3 ) {
            ++cnt;
            return;
        }
        
        _dfs( unit, rating, rating_cur+1, cnt, mark );
        
        if ( (mark == SMALLER && rating[rating_cur] < unit.back()) ||
             (mark == BIGGER && rating[rating_cur] > unit.back()) ) {
            unit.push_back(rating[rating_cur]);
            _dfs( unit, rating, rating_cur+1, cnt, mark );
            unit.pop_back();
        }
    }
    
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0;
        vector<int> unit;
        
        for (int i = 0; i <= rating.size()-3; ++i) {
            unit.push_back(rating[i]);
            _dfs(unit, rating, i+1, cnt, BIGGER);
            _dfs(unit, rating, i+1, cnt, SMALLER);
            unit.pop_back();
            
        }
        
        return cnt;
    }
};