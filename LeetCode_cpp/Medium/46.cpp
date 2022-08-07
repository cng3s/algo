class Solution {
private:
    vector<vector<int>> _ans;
    vector<bool> _vis;
    vector<int> _res;
    int _n;

    void _dfs(vector<int>& nums) {
        if ( _n == _res.size() ) {
            _ans.push_back( _res );
        }

        for ( int i = 0; i < _n; ++i ) {
            if ( !_vis[i] ) {
                _res.push_back(nums[i]);
                _vis[i] = true;
                _dfs(nums);
                _res.pop_back();
                _vis[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        _n = nums.size();
        if ( _n == 0 ) { return _ans; }
        
        _vis.resize(_n, false);
        _dfs(nums);

        return _ans;
    }
};