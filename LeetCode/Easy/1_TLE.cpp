// 超时

class Solution {
private:
    static bool _cmp( pair<int, int>& p1, pair<int, int>& p2 ) { return p1.first < p2.first; }

    bool _dfs( vector<pair<int, int>>& num_idx, vector<int>& ans, vector<bool>& vis, int target, int left, int right) {
        if ( ans.size() == 2 ) { return target == 0; }
        if ( left > right ) { return false; }

        for ( int i = right; i >= 0; --i ) {
            int idx = num_idx[i].second, val = num_idx[i].first;
            ans.push_back( idx );
            vis[i] = true;

            if (_dfs( num_idx, ans, vis, target-val, left, i-1 )) { return true; }

            vis[i] = false;
            ans.pop_back();
        }

        return false;
    }

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> num_idx;
        vector<int> ans;
        vector<bool> vis( n, false );

        for ( int i = 0; i < n; ++i ) { num_idx.push_back({nums[i], i}); }
        sort( num_idx.begin(), num_idx.end(), _cmp );

        _dfs( num_idx, ans, vis, target, 0, n-1 );
        return ans;
    }
};